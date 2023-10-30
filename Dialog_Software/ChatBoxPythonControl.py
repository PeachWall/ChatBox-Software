# ChatBoxPythonControl is a program that acts as a bridge between the
# Chat Ai to the robot control programs. To do this we connect our python
# script to dialog flow through Google cloud. This must be done by acquiring a key
# we can then use serial communication to communicate with an arduino cpu which
# will control our robot.


# Importing all required libraries
import pyttsx3
import os
import google.cloud.dialogflow_v2 as dialogflow
import serial
import time
from playsound import playsound
# import pyfirmata2     # Not in use
# import pyaudio        # Not in use
from vaderSentiment.vaderSentiment import SentimentIntensityAnalyzer
import speech_recognition as speech
from google.api_core.exceptions import InvalidArgument

# initialising sentiment analyser
sid_obj = SentimentIntensityAnalyzer()

# Simplify intents
# intentDict = {
#     "CheckinIntent": "Check",
#     "SmallTalkIntent": "SmallTalk",
#     "Default Welcome Intent": "Welcome",
#     "Default Fallback Intent": "Fallback"
# }

# Serial setup
serialComm = serial.Serial('COM9', 9600)
serialComm.timeout = 1

# Text to speech setup
engine = pyttsx3.init()
voices = engine.getProperty('voices')
volume = engine.getProperty('volume')

engine.setProperty('voice', voices[1].id)  # Set voice Type, (1 = female), (0 = male)
engine.setProperty('rate', 145)  # Set Voice Rate
engine.setProperty('volume', 1.0)  # Set Voice Volume (Range = 0 - 1)

# ???
for i in range(1):
    playsound('TacoBELL.mp3')
    engine.runAndWait()
engine.stop()

# Speech to text
r = speech.Recognizer()
audio_text = 'empty'
voiceInput = ''


# speaking
def speak(text):
    engine.say(text)
    engine.runAndWait()
    engine.stop()


# listening
def listen():
    # Receiving input from microphone
    # listening to speech and storing speech in audio_text variable
    global voiceInput
    with speech.Microphone() as source:
        print("Receiving input")
        speak("I'm listening")
        r.adjust_for_ambient_noise(source, duration=1)
        audio_text = r.listen(source)
        print("Input received")
        speak("")
        # recognize_() method will throw a request error if the API is unreachable, hence using exception handling

        try:
            # Using google speech recognition
            voiceInput = r.recognize_google(audio_text)
            print("Text: " + voiceInput)

        except:
            print("Sorry, I did not get that")


# Sending the data off to dialog flow and receiving an input
def understand():
    # Connect with Google dialogflow
    global voiceInput
    # json key
    os.environ["GOOGLE_APPLICATION_CREDENTIALS"] = 'private_key.json'

    DIALOGFLOW_PROJECT_ID = 'newagent-oybd'
    DIALOGFLOW_LANGUAGE_CODE = 'en'
    SESSION_ID = 'monke' # <--- this can be repalced with anything

    # Send recognized text to dialogflow
    # find sentiment value
    sentiment = sid_obj.polarity_scores(voiceInput)['compound']
    print(sentiment)
    # set tge input as text_to_be_analyzed
    text_to_be_analyzed = voiceInput
    # Initialize connection with client
    session_client = dialogflow.SessionsClient()
    session = session_client.session_path(DIALOGFLOW_PROJECT_ID, SESSION_ID)
    text_input = dialogflow.types.TextInput(text=text_to_be_analyzed, language_code=DIALOGFLOW_LANGUAGE_CODE)
    query_input = dialogflow.types.QueryInput(text=text_input)
    try:
        response = session_client.detect_intent(session=session, query_input=query_input)
    except InvalidArgument:
        raise

    # Print information from client
    print("Query text:", response.query_result.query_text)
    print("Detected intent:", response.query_result.intent.display_name)
    print("Detected intent confidence:", response.query_result.intent_detection_confidence)
    print("Fulfillment text:", response.query_result.fulfillment_text)

    # Send information to robot
    if not serialComm.is_open:
        serialComm.open()

    # intent = intentDict[response.query_result.intent.display_name].encode('ascii')    used when using intentDict
    intent = response.query_result.intent.display_name.encode('ascii')
    serialInfo = (intent.decode('ascii') + "/" + str(sentiment) + "/" + response.query_result.fulfillment_text[-1])
    print(serialInfo)
    serialComm.write(serialInfo.encode('ascii'))
    time.sleep(0.5)
    print(serialComm.readline().decode('ascii'))
    time.sleep(0.5)
    speak(response.query_result.fulfillment_text)
    # serialComm.close()


# ***** MAIN LOOP *****
while True:
    i = input("Enter command: ").strip()
    if i == 'terminate':
        serialComm.write('0'.encode())
        print('terminated')
        break
    elif len(i) <= 2:
        serialComm.write(i.encode())
        print(i + ' sent')
        # audio input (listening) <---
    elif i == 'lis':
        listen()
        understand()
        # text input (reading) <---
    elif i == 'tex':
        j = input("Type message: ").strip()
        voiceInput = j
        understand()
    time.sleep(1)
