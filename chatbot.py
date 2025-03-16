import google.generativeai as genai

API_KEY="AIzaSyBNAi5d6n7MRo3U7RDuNzwI_DyZLIPouWc"
genai.configure(api_key=API_KEY)
model=genai.GenerativeModel("gemini-pro")

def fun():
    print("Chat bot: yo! type exit for exiting ")
    while(1):
        user_in = input()
        if(user_in.lower()=="exit"):
            print("TQ")
            break
        try:
            response = model.generate_content(user_in)
            print(f"Chat bot :{response.text}")
        except Exception as e:
            print(f"Chat bot:{e}")

fun()