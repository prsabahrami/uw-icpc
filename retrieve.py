from requests import *
from bs4 import BeautifulSoup
import os

def save_dir(url):
    # recursively save the directory
    response = get(url)
    html = response.text
    soup = BeautifulSoup(html, 'html.parser')
    files = soup.find_all('a')
    
    for obj in files:
        if obj.get('href'):
            # check if obj is a file or a directory
            if obj.get('href')[-1] == '/' and obj.get('href')[:8] != "/~acm00/":
                os.system(f'mkdir -p {obj.get("href")}')
                os.chdir(obj.get('href'))
                save_dir(url + obj.get('href'))
                os.chdir('..')
            elif "=" not in obj.get('href'):
                file_url = url + obj.get('href')
                os.system(f'wget {file_url}')

def main():
    url = 'https://uwaterloo.ca/international-collegiate-programming-contest/past-local-contest-results'
    
    # find all hyperlinks in the page
    response = get(url)
    html = response.text
    soup = BeautifulSoup(html, 'html.parser')
    links = soup.find_all('a')

    # filter the links that start with acm
    links = [link.get('href') for link in links if link.get('href') and 'acm' in link.get('href')]

    # remove the ones ending with score.html or standing
    links = [link for link in links if 'score' not in link and 'standing' not in link and "practice" not in link 
             and "statement" not in link and "data" not in link and "http://acm.student.cs.uwaterloo.ca/~acm00/" in link]

    links = [link[:48] for link in links if link[42:48].isnumeric()]

    # remove the duplicates
    links = list(set(links))

    # create a directory to store the files
    os.system('mkdir -p data')
    os.chdir('data')

    # download the files
    for link in links:
        # get the list of files available in this page
        response = get(link)
        html = response.text
        soup = BeautifulSoup(html, 'html.parser')
        files = soup.find_all('a')
        
        if link[-1] == '/':
            link = link[:-1]
        
        os.system(f'mkdir -p {link[42:]}')
        os.chdir(link[42:])

        save_dir(link + '/')
        os.chdir('..')

if __name__ == '__main__':
    main()
