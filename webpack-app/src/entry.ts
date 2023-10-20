import { GameSystem, iStarfinderDoc } from "./lib/mappings/json_map.js";
import { JsonExtractor } from "./lib/workers/json_extractor.js";
import { GetPdfData, PdfData } from "./lib/workers/pdf_extractor.js";
import * as ImageSaver from "./lib/workers/image_saver.js";

//  no_schema: boolean
export default async function entry(pdf_path: File, output_path: string) {
  // Get PDF
  let pdf_data = await GetPdfData(pdf_path);

  // if (no_schema === true) {
  //   await ImageSaver.printAllImages(output_path, pdf_data.images, ImageSaver.Extension.png);
  // } else {
    // Get schema
    let json_schema = (JsonExtractor(GameSystem.Starfinder, pdf_data.title) as iStarfinderDoc);
    if (json_schema === undefined) {
      console.log("schema not found");
    } else {
      // Map images
      let x = await Promise.all(Object.entries(json_schema.assets).map(async ([assetType, dictionary]) => {
        const folder = `${output_path}/${json_schema.name}/${assetType}`;
        // await fs.promises.mkdir(folder, { recursive: true });
        return ImageSaver.generateJNodeImages(folder, dictionary, pdf_data.images);
      }));
      // for (let index = 0; index < x.length; index++) {
      //   game_map.push(...x[index]);
      // }
    }
  // }


  return pdf_data;
}