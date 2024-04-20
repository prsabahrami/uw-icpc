import weasyprint
import os

def main():
    # iterate over all files in the directory
    for root, dirs, files in os.walk('.'):
        for file in files:
            if file.endswith('.htm'):
                # convert the file to pdf
                html = weasyprint.HTML(root + '/' + file)
                html.write_pdf(root + '/' + file.replace('.htm', '.pdf'))
                print(f'{file} converted to pdf')

                # remove the html file
                os.system(f'rm {root}/{file}')
            elif file.endswith('.html'):
                # convert the file to pdf
                html = weasyprint.HTML(root + '/' + file)
                html.write_pdf(root + '/' + file.replace('.html', '.pdf'))
                print(f'{file} converted to pdf')

                # remove the html file
                os.system(f'rm {root}/{file}')
    remove()

def remove():
    # iterate over all files in the directory
    for root, dirs, files in os.walk('.'):
        for file in files:
            if "html" in file or file.endswith('.jpg') or file.endswith('.png') or file.endswith('.jpeg') or file.endswith('.gif') or file.endswith('.GIF'):
                # remove the html file
                os.system(f'rm "{root}/{file}"')

if __name__ == '__main__':
    main()