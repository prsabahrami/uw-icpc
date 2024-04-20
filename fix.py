import os

def main():
    # iterate over all folders in directory and check if there is data folder
    for dirs in os.listdir('.'):
        if not 'data' in os.listdir(dirs):
            os.chdir(dirs)
            os.system(f'wget -r -np -nH --cut-dirs=2 -R index.html,yyy,yyy.html,xxx https://icpc.student.cs.uwaterloo.ca/~acm00/{dirs}/data/')
            os.chdir('..')

if __name__ == '__main__':
    main()
