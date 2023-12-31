# ChatBox-Software
Welcome to the ChatBox repo! This GitHub repository houses code incorporating Dialogflow language processing with Arduino hardware control. 
It contains Python scripts for Dialogflow interactions and Arduino .ino files for hardware control. 

## Setup Instructions

1. To use the Dialogflow functions in the code, you will first need to obtain an API key from google cloud. Visit the google dialog flow console and enable the API services for DialogFlow.  

2. Then navigate to DialogFlow console and go to the agent settings page by clicking the gear icon. From here access the service account page.

3. Click the create new key button. Make sure that you select a .JSON type key. 

4. Once you have your API key, create a new file in the root directory of this project named `.env`.

5. Inside the `.env` file, add the following: 

    # Dialogflow API credentials
    GOOGLE_APPLICATION_CREDENTIALS = your_google_credentials_here

    # Dialogflow API settings
    DIALOGFLOW_PROJECT_ID          = your_project_id_here
    DIALOGFLOW_LANGUAGE_CODE       = your_language_code
    SESSION_ID                     = your_session_id

6. Save the `.env` file. The Python scripts in this project are set up to read the API key from this file, so you should now be able to use the Dialogflow functions.

