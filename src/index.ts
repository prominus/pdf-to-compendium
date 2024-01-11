import fs from "fs";
import { args } from "./args";
import { test } from "@foundry";
import { GameSystem, iStarfinderDoc } from "@mappings";
import { GetPdfDafa, ImageSaver, JsonExtractor } from "@workers";

export interface Args {
  no_schema: boolean,
  pdf_path: string,
  output_path: string
}

async function main(args: Args) {
  try {
    // Get PDF
    let pdf_data = await GetPdfDafa(args.pdf_path);

    // Get schema
    let json_schema = (JsonExtractor(GameSystem.Starfinder, pdf_data.title) as iStarfinderDoc);
    if (json_schema == undefined && args.no_schema === false) {
      console.log("schema not found");
      return;
    }

    if (args.no_schema === true) {
      await ImageSaver.printAllImages(args.output_path, pdf_data.images, ImageSaver.Extension.png);
    } else {
      // Map images
      Object.entries(json_schema.assets).forEach(async ([assetType, dictionary]) => {
        // const key = Object.keys(json_schema.alien_archives)[0];
        const folder = `${args.output_path}/${json_schema.name}/${assetType}`;
        await fs.promises.mkdir(folder, { recursive: true });
        await ImageSaver.generateJNodeImages(folder, ['actor', 'token'], dictionary, pdf_data.images);

      });
    }


    // TODO: determine what images to save
    // await printAllImagesToWebP(args.output_path, pdf_data.images);
  } catch (error) {
    console.log(`Error running main: ${error}`);
  }
}

await main(args);