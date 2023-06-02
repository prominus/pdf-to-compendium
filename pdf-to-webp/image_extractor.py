# https://www.youtube.com/watch?v=vsYi1uhUAL0
from pikepdf import Pdf, PdfImage

class ImageExtractor:

    def extract_images(file:str):
        pdf = Pdf.open(file)

        for pn, page in enumerate(pdf.pages, 1):
            for key in page.images.keys():
                name = str(key).replace('/', '')
                raw_image = page.images[key]
                pdf_image = PdfImage(raw_image)
                pdf_image.extract_to(fileprefix=f'img/page-{pn}-{name}')


def __test():
    file = r"C:/Users/Magenta/Documents/Starfinder/Starfinder - Alien Archive 1.pdf"

    ImageExtractor.extract_images()

if __name__ == '__main__':
    __test()