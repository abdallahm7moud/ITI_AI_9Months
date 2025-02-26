import re
import os
import json
import time
from datetime import datetime



user_data = {}
projects = {}
current_user = None


def validate_phone(phone_number):
    pattern = re.compile(r"^01[0-2,5]{1}[0-9]{8}$")
    valid_phone= pattern.match(phone_number)
    return valid_phone



def validate_email(email):
    regex = r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,7}\b'
    valid_email = re.fullmatch(regex, email)
    return valid_email



def validate_password(password):
    pattern = re.compile(r"^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#\$%\^&\*])(?=.{8,})")
    valid_password= pattern.match(password)
    return valid_password



def ask_for_fname():
    while True:
        os.system('cls')
        fname = input("Enter first name: ").strip()
        if fname == "" or fname.isalpha() == False or len(fname) < 3:
            print("Enter a valid first name.")
            time.sleep(2)
        else:
            return fname
        
        

def ask_for_lname():
    while True:
        lname = input("Enter last name: ").strip()
        if lname == "" or lname.isalpha() == False or len(lname) < 3:
            print("Enter a valid last name.")
        else:   
            return lname        
        


def ask_for_email():
    while True:
        os.system('cls')
        email = input("Enter email: ").strip()
        if email in user_data:
            print("Email already registered.")
        elif not validate_email(email):
            print("Invalid email. Please enter a valid email.")
        else:
            return email
        


def ask_for_phone_number():
    while True:
        phone_number = input("Enter phone number: ").strip()
        if not validate_phone(phone_number):
            print("Invalid phone number. Please enter a valid Egyptian phone number.")
        else:
            return phone_number



    
def ask_for_password():
    while True:
        password = input("Enter password: ")
        if not validate_password(password):
            print("Invalid password. Please enter a valid password.")
        else:
            confirm_password = input("Confirm password: ")
            if password != confirm_password:
                print("Passwords do not match. Please try again.")
            else:
                return password
   



        
def save_data():
    try:
        with open("users.json", "w") as file:
            json.dump(user_data, file,indent=4)
    except Exception as e:
            print(e)
      
        

def load_data():
    try:
        with open("users.json", "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return {}
    
    

def save_projects():
    try:
        with open("projects.json", "w") as file:
            json.dump(projects, file,indent=4)
    except Exception as e:
            print(e)
      
        

def load_projects():
    try:
        with open("projects.json", "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return {}
   



def register():
    global user_data
    print("======Welcome to the registration page======")
    
    first_name = ask_for_fname()
    last_name = ask_for_lname()
    registration_email = ask_for_email()
    phone = ask_for_phone_number()
    registration_password = ask_for_password()
    
    user_data = load_data()
    user_data[registration_email] = {
        "first_name": first_name,
        "last_name": last_name,
        "password": registration_password,
        "phone": phone
    }
    save_data()
    print("Registration successful")
      
      
      
      

def login():
    while True:
        global current_user
        global user_data
        user_data = load_data()
        os.system('cls')
        print("======Welcome to the Login page======")
        Login_email = input("Enter email: ").strip()
        Login_password = input("Enter password: ").strip()
        user = user_data.get(Login_email)
        if not user:
            print("No account found with this email.")
            time.sleep(2)
       
        elif user["password"] != Login_password:
            print("Incorrect password.")
            time.sleep(2)
        else:
            current_user = Login_email
            print("Login successful")
            print(f"Welcome back, {user['first_name']}!")
            break
        
        
         

    
    
def create_project():
    global projects
    while True:
        os.system('cls')
        print("=== Create Project ===")
        title = input("Project Title: ").strip()
        if title == "":
                print("Enter a valid title.")
                time.sleep(2)
        else:    
            details = input("Project Details: ").strip()
            if details == "":
                    print("Enter a valid title.")
                    time.sleep(2)
            else:
                break
    
    while True:
        target = input("Total Target (EGP): ").strip()
        try:
            target = float(target)
            break
        except ValueError:
            print("Invalid target amount!")
       
    while True:   
        start_date = input("Start Date (YYYY-MM-DD): ").strip()
        end_date = input("End Date (YYYY-MM-DD): ").strip()
        try:
            start_date = datetime.strptime(start_date, "%Y-%m-%d").date()
            end_date = datetime.strptime(end_date, "%Y-%m-%d").date()
            break
        except ValueError:
            print("Invalid date format!")
        
    projects = load_projects() 
    project_id = len(projects) + 1
    projects[project_id] = {
        "title": title,
        "details": details,
        "target": target,
        "start_date": str(start_date),
        "end_date": str(end_date),
        "owner": current_user
    }
    save_projects()
    print("Project created successfully!")
    
    
    
    
    
def view_all_projects():
    global projects
    projects = load_projects()
    print("=== All Projects ===")
    for pid, project in projects.items():
        print(f"ID: {pid}, Title: {project['title']}, ,Target: {project['target']} EGP, Start: {project['start_date']}, End: {project['end_date']}")
    
      
      
      
      
        
def delete_project():
    global projects
    projects = load_projects()
    
    if not projects:
        print("No projects available to delete.")
        time.sleep(2)
        return
    
    while True: 
        os.system('cls')  
        project_id = input("Enter Project ID to delete: ").strip()
        if project_id not in projects:
            print("Invalid Project ID!")
            time.sleep(2)
        else:
            if projects[project_id]["owner"] != current_user:
                print("You can only delete your own projects!")
                time.sleep(2)
            else:
                break
       
    del projects[project_id]
    save_projects()
    print("Project deleted successfully!")
    
    
    
    
    
    
def search_projects():
    global projects
    projects = load_projects()
    while True:
        os.system('cls')
        date = input("Enter date to search (YYYY-MM-DD): ").strip()
        try:
            date = datetime.strptime(date, "%Y-%m-%d").date()
            found = False
           
            print(f"=== Projects on {date} ===")
            for project in projects.values():
                start_date = datetime.strptime(project["start_date"], "%Y-%m-%d").date()
                end_date = datetime.strptime(project["end_date"], "%Y-%m-%d").date()
                
                if start_date <= date <= end_date:
                    print(f"Title: {project['title']}, details: {project['details']}, Target: {project['target']} EGP")
                    found = True
            if not found:
                print("No projects found on this date!")
                time.sleep(2)
            else:
                break
                
        except ValueError:
            print("Invalid date format!")
            time.sleep(2)
        
        
      
             
        
def edit_project():
    global projects
    projects = load_projects()
    while True:
        os.system('cls')
        project_id = input("Enter Project ID to edit: ").strip()
        
        if project_id not in projects:
            print("Invalid Project ID!")
            time.sleep(2)
        else:
            if projects[project_id]["owner"] != current_user:
                print("You can only edit your own projects!")
                time.sleep(2)
            else:
                break
                         
    print("=== Edit Project ===")
    title = input("Project Title: ").strip()
    details = input("Project Details: ").strip()
        
    while True:
        target = input("Total Target (EGP): ").strip()
        try:
            target = float(target)
            break
        except ValueError:
            print("Invalid target amount!")

    while True:   
        start_date = input("Start Date (YYYY-MM-DD): ").strip()
        end_date = input("End Date (YYYY-MM-DD): ").strip()
        try:
            start_date = datetime.strptime(start_date, "%Y-%m-%d").date()
            end_date = datetime.strptime(end_date, "%Y-%m-%d").date()
            break
        except ValueError:
            print("Invalid date format!")

        
    projects[project_id] = {
        "title": title,
        "details": details,
        "target": target,
        "start_date": str(start_date),
        "end_date": str(end_date),
        "owner": current_user 
    }
    save_projects()
    print("Project edited successfully!")




    
def main_page():
    print("==========welcome to the main page==========")
    print("1. Create Project")
    print("2. View All Projects")
    print("3. Edit Project")
    print("4. Delete Project")
    print("5. Search Projects by Date")
    print("6. Logout")
    mainn = input("Enter your choice: ")
    if mainn == "1":
        os.system('cls')
        create_project()
        time.sleep(5)
        os.system('cls')
        main_page()
    elif mainn == "2":
        os.system('cls')
        view_all_projects()
        time.sleep(5)
        os.system('cls')
        main_page()
    elif mainn == "3":
        os.system('cls')
        edit_project()
        time.sleep(5)
        os.system('cls')
        main_page()
    elif mainn == "4":
        os.system('cls')
        delete_project()
        time.sleep(5)
        os.system('cls')
        main_page()
    elif mainn == "5":
        os.system('cls')
        search_projects()
        time.sleep(5)
        os.system('cls')
        main_page()
    elif mainn == "6":
        global current_user
        current_user = None
        print("Logout Successful")
        time.sleep(5)
        os.system('cls')
        app()
    else:
        print("Invalid choice. Please try again.")
        main_page()





def app():
    print("1. Register")
    print("2. Login")
    print("3. Exit")
    choice = input("Enter your choice: ")
    if choice == "1":
        register()
        time.sleep(5)
        os.system('cls')
        app() 
    elif choice == "2":
        login()
        time.sleep(5)
        os.system('cls')
        main_page()

    elif choice == "3":
        print("Goodbye!")
        return
    else:
        print("Invalid choice. Please try again.")
        time.sleep(2)
        os.system('cls')
        app()





if __name__ == "__main__":
    app()
