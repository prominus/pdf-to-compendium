// Based on: https://stackoverflow.com/questions/70737205/extract-images-from-pdf-file-with-jspdf-or-other-npm-package

import { PDFDocument } from "pdf-lib";
import fs from 'fs';
import { getMimeType } from 'stream-mime-type';

async function getImageFromPdf(document: string) {
    const pdfData = fs.readFileSync(document)
    const pdfDoc = await PDFDocument.load(pdfData, { ignoreEncryption: true });
    const pages = pdfDoc.getPages();
    const result:any[] = []
    // @ts-ignore
    pages[0].doc.context.indirectObjects.forEach(el => {
        if (el.hasOwnProperty('contents')) result.push(el.contents)
    })
    const mime = await Promise.all(result.map(async (el) => {
        return new Promise(async (resolve) => {
            // @ts-ignore
            const res = await getMimeType(el)
            if (res) {
                resolve(res)
            }
        })
    }));
    await Promise.all(mime.map(async (el, i) => {
        // @ts-ignore
        if (el.mime === 'image/jpeg') {
            return new Promise(async (resolve) => {
                const res = await writeJpgFile(result[i], `image-${i}`,
                    'jpg')
                resolve(res)
            })
        }
    })
    )
}

function writeJpgFile(arg0: any, arg1: string, arg2: string) {
    throw new Error("Function not implemented.");
}

getImageFromPdf("C:/Users/Magenta/Documents/Starfinder/starfinderpdftofoundry/src/img/Game Master's Guide.pdf")
