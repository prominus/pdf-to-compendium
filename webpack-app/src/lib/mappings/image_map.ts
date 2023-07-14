// import sharp from "sharp";

export class GameMap {
    public imageFilePath: string = "icons/svg/mystery-man.svg";
    constructor(
        public id:string,
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
    public bytes: number;
    public crop?: any; // sharp.Region;
    /**
     * 
     * @param name - The image name as defined in the PDF
     * @param width - Pixel width of the raw image
     * @param height - Pixel height of the raw image
     * @param data - The raw image data extracted from the PDF
     */
    constructor(
        public name: string,
        public width: number,
        public height: number,
        public data: Uint8Array
    ) {
        this.bytes = data.length;
        this.mappings = [];
    }

    /**
     * Return the channel to use in generating a Raw image
     */
    public channels() {
        let channels: 1 | 2 | 3 | 4 = 1;
        let c = this.bytes / this.width / this.height;
        if (c > 4) {
            channels = 4;
        } else if (c < 1) {
            channels = 1;
        } else {
            channels = c as 1 | 2 | 3 | 4;
        }
        return channels;
    };

}