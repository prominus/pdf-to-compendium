import { ImageMap, iDictionary } from "@mappings";
import sharp from "sharp";

export enum Extension {
    jpg = 'jpg',
    png = 'png',
    webp = 'webp',
}

/**
 * Save images to an output folder
 * @param outputFolder - Location to save the images
 * @param images - List of images to save
 */
export async function printAllImages(outputFolder: string, images: ImageMap[], extension: Extension) {
    images.forEach(async (image: ImageMap) => {
        const file = outputFolder + `/${image.name}.${extension.valueOf()}`;
        await saveWebPImage(image, file);
    });
}

// 
export async function generateJNodeImages(prefix: string, extMods: string[], dictionary: iDictionary, images: ImageMap[]) {
    const re1 = /[ ]/gi;
    const re2 = /[\W]/gi;
    const re3 = /[_]/gi;
    Object.entries(dictionary).forEach(([key, value]) => {

        // let files = extMod.map(x => `${outputFolder}/${jsonKey.toLowerCase().replace(re1, '_').replace(re2, '').replace(re3, '-')}.${x}.webp`);
        extMods.forEach(async x => {
            // Create the file
            const file = `${prefix}/${key.toLowerCase().replace(re1, '_').replace(re2, '').replace(re3, '-')}.${x}.webp`;
            // Special case for token
            if (x === 'token' && value.icon !== undefined) {
                const image = images.find(y => y.name === value.icon);
                // TODO - put it in a circle banner
                await saveWebPImage(image, file);
            } else {
                const image = images.find(y => y.name === value.orig);
                await saveWebPImage(image, file);
            }

        });
    });
}

async function saveWebPImage(image: ImageMap | undefined, file: string) {
    if (image != undefined) {
        const width = image.width;
        const height = image.height;
        const channels = image.channels();
        await sharp(image.data, {
            raw: { width, height, channels }
        }).toFile(file);
        console.log(`Image saved ${file}`);
    }
}
