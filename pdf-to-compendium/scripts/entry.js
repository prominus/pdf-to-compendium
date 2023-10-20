import { GameSystem } from "./lib/mappings/json_map.js";
import { JsonExtractor } from "./lib/workers/json_extractor.js";
import { GetPdfData } from "./lib/workers/pdf_extractor.js";
import * as ImageSaver from "./lib/workers/image_saver.js";
export default async function entry(pdf_path, output_path) {
    let pdf_data = await GetPdfData(pdf_path);
    let json_schema = JsonExtractor(GameSystem.Starfinder, pdf_data.title);
    if (json_schema === undefined) {
        console.log("schema not found");
    }
    else {
        let x = await Promise.all(Object.entries(json_schema.assets).map(async ([assetType, dictionary]) => {
            const folder = `${output_path}/${json_schema.name}/${assetType}`;
            return ImageSaver.generateJNodeImages(folder, dictionary, pdf_data.images);
        }));
    }
    return pdf_data;
}
//# sourceMappingURL=entry.js.map