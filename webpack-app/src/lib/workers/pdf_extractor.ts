// https://github.com/Hopding/pdf-lib/issues/83
import { PDFDocument, PDFName, PDFRawStream } from "pdf-lib";
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

function readBlobAsArrayBuffer(blob: File) {
    return new Promise((resolve, reject) => {
        const reader = new FileReader();

        reader.onload = () => {
            const arrayBuffer = reader.result;
            resolve(arrayBuffer);
        };

        reader.onerror = () => {
            reader.abort();
            reject(new Error('Failed to read Blob as Array Buffer.'));
        };

        reader.readAsArrayBuffer(blob);
    });
}

/**
 * Extract all images and metadata from a PDF
 * 
 * @param path - Absolute file path to PDF
 * @returns A promised list of images and metadata from the PDF 
 */
export async function GetPdfData(path: File) {
    const imagesContainer = document.getElementById('images');
    //@ts-ignore
    const blobBuffer: ArrayBuffer = await readBlobAsArrayBuffer(path);
    const u = URL.createObjectURL(path)
    console.log(u.indexOf('XObject'))
    let pdfDoc = await PDFDocument.load(blobBuffer, { ignoreEncryption: true });
    const enumeratedIndirectObjects =
        pdfDoc.context.enumerateIndirectObjects();

    //@ts-ignore
    const t: string = (pdfDoc.getTitle() != undefined ? pdfDoc.getTitle() : "");
    //@ts-ignore
    const a: string = (pdfDoc.getAuthor() != undefined ? pdfDoc.getAuthor() : "");
    //@ts-ignore
    const d: string = (pdfDoc.getCreationDate() != undefined ? pdfDoc.getCreationDate() : "")?.toString();
    let pdf_data = new PdfData(
        t,
        a,
        d
    );

    let objectIdx = 0;
    enumeratedIndirectObjects.forEach(async ([pdfRef, pdfObject], ref: number) => {
        if (!(pdfObject instanceof PDFRawStream)) return;

        const { dict } = pdfObject;

        const smaskRef = dict.get(PDFName.of('SMask'));
        const colorSpace = dict.get(PDFName.of('ColorSpace'));
        const subtype = dict.get(PDFName.of('Subtype'));
        const width: any = dict.get(PDFName.of('Width'));
        const height: any = dict.get(PDFName.of('Height'));
        const name = dict.get(PDFName.of('Name'));
        const bitsPerComponent: any = dict.get(
            PDFName.of('BitsPerComponent')
        );
        const filter = dict.get(PDFName.of('Filter'));
        const decode = PDFName.of('DCTDecode')

        if (
            subtype == PDFName.of('Image') &&
            smaskRef != undefined &&
            colorSpace != undefined &&
            subtype != undefined &&
            width != undefined &&
            height != undefined &&
            bitsPerComponent != undefined &&
            filter != undefined &&
            decode != undefined
        ) {
            objectIdx += 1;
            pdf_data.images.push(
                new ImageMap(
                    ref,
                    smaskRef,
                    colorSpace,
                    `Image${objectIdx}`,
                    width.numberValue,
                    height.numberValue,
                    bitsPerComponent.numberValue,
                    pdfObject.contents,
                    filter === decode ? 'jpg' : 'png'
                )
            )
        }
    });

    // test printing images on page
    for (const image of pdf_data.images) {
        // // @ts-ignore
        // const imageData: BlobPart =
        //     image.type === 'jpg' ? image.data : await savePng(image);
        const imgElement = document.createElement('img');
        imgElement.setAttribute(
            'src',
            URL.createObjectURL(
                new Blob([image.data], { type: `image/${image.type}` })
            )
        );
        imgElement.setAttribute('width', image.width.toString());
        imgElement.setAttribute('height', image.height.toString());

        if (imagesContainer != null) {
            imagesContainer.appendChild(imgElement);
        }
        
    }
    return pdf_data;
}