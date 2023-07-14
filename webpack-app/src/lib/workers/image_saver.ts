import { GameMap, ImageMap } from "../mappings/image_map.js";
import { iDictionary } from "../mappings/json_map.js";
// import sharp from "sharp";

export enum Extension {
    jpg = 'jpg',
    png = 'png',
    webp = 'webp',
}

// /**
//  * Save images to an output folder
//  * @param outputFolder - Location to save the images
//  * @param images - List of images to save
//  */
// export async function printAllImages(outputFolder: string, images: ImageMap[], extension: Extension) {
//     images.forEach(async (image: ImageMap) => {
//         const file = outputFolder + `/${image.name}.${extension.valueOf()}`;
//         await saveImage(image, file);
//     });
// }

// 
export function generateJNodeImages(prefix: string, dictionary: iDictionary, images: ImageMap[]) {
    // ['actor', 'token']
    const re1 = /[ ]/gi;
    const re2 = /[\W]/gi;
    const re3 = /[_]/gi;
    Object.entries(dictionary).map(([key, value]) => {
        // Create the files
        const token_path = `${prefix}/${key.toLowerCase().replace(re1, '_').replace(re2, '').replace(re3, '-')}.token.png`;
        const file_path = `${prefix}/${key.toLowerCase().replace(re1, '_').replace(re2, '').replace(re3, '-')}.actor.png`;
        // Special case for token
        const image = images.find(y => y.name === value.orig);
        if (image !== undefined) {
            image.mappings.push(new GameMap(value.id, file_path));
        }
        // Save token
        if (value.icon !== undefined) {
            const icon = images.find(y => y.name === value.icon);
            // TODO - put it in a circle banner
            if (icon !== undefined) {
                icon.mappings.push(new GameMap(value.id, token_path));
            }
            // await saveToken(icon, token);
            // } else {
            //     await tokenizeOriginalImage(image, token_path);
        }
        // Save image
        // await saveImage(image, file);
        // return new GameMap(value.id, file, token_path);
    });

}

// async function saveImage(image: ImageMap | undefined, file: string) {
//     if (image != undefined) {
//         const width = image.width;
//         const height = image.height;
//         const channels = image.channels();
//         await sharp(image.data, {
//             raw: { width, height, channels }
//         }).toFile(file);
//         console.log(`Image saved ${file}`);
//     }
// }

// const tokenizeImage = Buffer.from(
//     '<svg><rect x="0" y="0" width="256" height="256" rx="256" ry="256"/></svg>'
// );

// async function saveToken(image: ImageMap | undefined, file: string) {
//     if (image != undefined) {
//         const width = image.width;
//         const height = image.height;
//         const channels = image.channels();
//         await sharp(image.data, {
//             raw: { width, height, channels }
//         })
//             .resize(256, 256)
//             .flatten({
//                 background: '#ffffff'
//             })
//             .composite([
//                 {
//                     input: tokenizeImage,
//                     blend: 'dest-in'
//                 }
//             ])
//             .toFile(file);
//         console.log(`Image saved ${file}`);
//     }
// }

// async function tokenizeOriginalImage(image: ImageMap | undefined, file: string) {
//     if (image != undefined) {
//         const width = image.width;
//         const height = image.height;
//         const channels = image.channels();
//         if (image.crop !== undefined) {
//             await sharp(image.data, {
//                 raw: { width, height, channels }
//             })
//                 .extract(image.crop)
//                 .resize(256, 256)
//                 .flatten({
//                     background: '#ffffff'
//                 })
//                 .composite([
//                     {
//                         input: tokenizeImage,
//                         blend: 'dest-in'
//                     }
//                 ])
//                 .toFile(file);
//         } else {
//             await sharp(image.data, {
//                 raw: { width, height, channels }
//             })
//                 .resize(256, 256)
//                 .flatten({
//                     background: '#ffffff'
//                 })
//                 .composite([
//                     {
//                         input: tokenizeImage,
//                         blend: 'dest-in'
//                     }
//                 ])
//                 .toFile(file);
//         }
//         console.log(`Image saved ${file}`);
//     }
// }
