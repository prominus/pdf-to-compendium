// import sharp from "sharp";

import { PDFName, PDFObject, PDFRef } from "pdf-lib";

export class GameMap {
    public imageFilePath: string = "icons/svg/mystery-man.svg";
    constructor(
        public id: string,
        imageFilePath: string,
    ) {
        this.imageFilePath = imageFilePath;
    }
}

/**
 * @param name - The image name as defined in the PDF
 * @param width - Pixel width of the raw image
 * @param height - Pixel height of the raw image
 * @param data - The raw image data extracted from the PDF
 * @param bytes
 */
export class ImageMap {

    public mappings: GameMap[];
    public crop?: any; // sharp.Region;
    /**
     * 
     * @param name - The image name as defined in the PDF
     * @param width - Pixel width of the raw image
     * @param height - Pixel height of the raw image
     * @param data - The raw image data extracted from the PDF
     */
    constructor(
        public ref: number,
        public smaskRef: PDFObject,
        public colorSpace: PDFObject,
        public name: string,
        public width: number,
        public height: number,
        public bitsPerComponent: number,
        public data: Uint8Array,
        public type: string
    ) {
        // this.bytes = data.length;
        this.mappings = [];
    }

}