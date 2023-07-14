// import { PDFDocumentProxy, PDFPageProxy, getDocument, OPS, GlobalWorkerOptions } from "pdfjs-dist";
// @ts-ignore
import pdfjs from "../pdfjs-dist/build/pdf.js";
// @ts-ignore
// import * as pdfjsWorker from "../pdfjs-dist/build/pdf.worker.js";
// const { getDocument, OPS } = pdfjs;
import { ImageMap } from "../mappings/image_map.js";

export class PdfData {
    public images: ImageMap[];
    constructor(
        public title: string,
        public author: string,
        public creationDate: string,
    ) {
        this.images = [];
    }
}

const workerSrc = `//cdnjs.cloudflare.com/ajax/libs/pdf.js/${pdfjs.version}/pdf.worker.js`;
pdfjs.GlobalWorkerOptions.workerSrc = workerSrc;

// Setting worker path to worker bundle.
// Do not have webpack try to bundle with project. This just causes errors
// pdfjs.GlobalWorkerOptions.workerSrc = './node_modules/pdfjs-dist/build/pdf.worker.entry.js';

/**
 * Extract all images and metadata from a PDF
 * 
 * @param path - Absolute file path to PDF
 * @returns A promised list of images and metadata from the PDF 
 */
export async function GetPdfData(path: File) {
    //@ts-ignore
    // const blobBuffer: ArrayBuffer = await readBlobAsArrayBuffer(path);
    const blobUrl = URL.createObjectURL(path);
    let pdf = await pdfjs.getDocument(blobUrl).promise;

    const metadata = await pdf.getMetadata();
    let pdf_data = new PdfData(
        (metadata.info as any)['Title'],
        (metadata.info as any)['Author'],
        (metadata.info as any)['CreationDate']
    );
    const totalNumPages = pdf.numPages;
    // Iterate over all pages and push images to pagePromises
    for (let currentPage = 1; currentPage <= totalNumPages; currentPage += 1) {
        const images = getPageImages(currentPage, pdf);
        pdf_data.images.push(...await images);
    }

    return pdf_data;
}

/**
 * Extract all images from the current PDF page
 * 
 * @param pageNum - The page number to grab
 * @param pdf - Reference to the PDF
 * @returns List of images from the PDF page
 */
async function getPageImages(pageNum: number, pdf: any) {
    const images: ImageMap[] = [];
    try {
        const pdfPage = await pdf.getPage(pageNum);
        const operatorList = await pdfPage.getOperatorList();

        // These indicate the element is an image
        const validObjectTypes = [
            pdfjs.OPS.paintXObject,
            pdfjs.OPS.paintImageXObject,
            pdfjs.OPS.paintInlineImageXObject
        ];

        // Iterate over each element in the page and store any element inferred to be an image
        operatorList.fnArray
            .forEach(async (element: any, idx: number) => {
                if (validObjectTypes.includes(element)) {
                    const imageName = operatorList.argsArray[idx][0];
                    pdfPage.objs.get(imageName, async (image: any) => {
                        console.log('page', pageNum, 'imageName', imageName, 'image', image);
                        if (image != null && image.data != null) {
                            const { width, height } = image;
                            let i = new ImageMap(imageName, width, height, image.data);
                            images.push(i);
                        }
                    });
                }
            });
    } catch (error) {
        console.log(error);
    }
    return images;
}

// async function getPageImages(pageNum: number, pdf: PDFDocumentProxy) {
//     const images: ImageMap[] = [];
//     try {
//         const pdfPage: PDFPageProxy = await pdf.getPage(pageNum);
//         const operatorList = await pdfPage.getOperatorList();

//         // These indicate the element is an image
//         const validObjectTypes = [
//             OPS.paintJpegXObject,
//             OPS.paintImageXObject,
//             OPS.paintInlineImageXObject
//         ];

//         // Iterate over each element in the page and store any element inferred to be an image
//         operatorList.fnArray
//             .forEach((element, idx) => {
//                 if (validObjectTypes.includes(element)) {
//                     const imageName = operatorList.argsArray[idx][0];
//                     console.log('page', pageNum, 'imageName', imageName);

//                     pdfPage.objs.get(imageName, async (image: any) => {
//                         const { width, height, _kind } = image;
//                         images.push(new ImageMap(imageName, width, height, image.data));
//                     });
//                 }
//             });
//     } catch (error) {
//         console.log(error);
//     }
//     return images;
