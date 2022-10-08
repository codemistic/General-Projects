

!pip install pdf2image
!apt-get install poppler-utils

# import OS module
import os
from pdf2image import convert_from_path

# not supported for direct pdf urls
pdf_url="/content/sample.pdf"

def isOuputFolderCreated(path):
    print(path)
    if not os.path.exists(path):
      
    # if the demo_folder directory is not present 
    # then create it.
        os.makedirs(path)

def convert_pdf_to_images(pdf_path):
    output_image_name=pdf_path.split("/")[-1].split(".")[0]
    a=pdf_url.split("/")
    del a[-1]
    base_dir="/".join(a)
    # print(pdf_path)
    # print(output_image_name)
    images = convert_from_path(pdf_path);
    isOuputFolderCreated(f'{base_dir}/output')
    for index, image in enumerate(images):
        # print(index,image)
        image.save(f'{base_dir}/output/{output_image_name}-{index+1}.png')
        # to display image in output
        # display(image) 


def task():
    convert_pdf_to_images(pdf_url)
    # convert_pdf_to_images('example-multipage.pdf')


if __name__ == "__main__":
    task()