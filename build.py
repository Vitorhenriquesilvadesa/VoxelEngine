import os

if __name__ == '__main__':
    premake_path = r'.\vendor\premake\premake5.exe'
    project_dir = r'project'
    project_file = 'premake5.lua'


    if not os.path.exists(premake_path):
        print(f"Error: {premake_path} not found.")
    elif not os.path.exists(project_file):
        print(f"Error: {project_file} not found.")
    else:
        return_code = os.system(f'{premake_path} vs2022 {project_file}')
        if return_code == 0:
            print("Successful!")
        else:
            print(f"The process returned with error code: {return_code}")