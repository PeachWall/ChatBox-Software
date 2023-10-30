import pyttsx3

# Text to speech setup
engine = pyttsx3.init()
voices = engine.getProperty('voices')

# Set voicetype, (2 = American female), (rate:150 = ??? )
engine.setProperty('voice', voices[0].id)

# Rate
rate = engine.getProperty('rate')
engine.setProperty('rate', 150)

# Volume
volume = engine.getProperty('volume')  # getting to know current volume level (min=0 and max=1)
print(volume)                          # printing current volume level
engine.setProperty('volume', 1.0)      # setting up volume level  between 0 and 1

for x in range(3):
    engine.say("wait")
    engine.runAndWait()
    engine.stop()

while True:
    i = input("Enter command: ").strip()
    if i == 'a':
        engine.say("go away")
        engine.runAndWait()
        engine.stop()
    if i == 's':
        engine.say("wee woo wee woo")
        engine.runAndWait()
        engine.stop()




