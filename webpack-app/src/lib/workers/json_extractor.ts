import { GameSystem } from "../mappings/json_map.js";
import { StarfinderList } from "../schemas/schemas.js";

/**
 * 
 * @param system - Specify the gaming system of choice
 * @param docName - Specify the name of the file
 * @returns The JSON schema for the PDF if found
 */
export function JsonExtractor(system: GameSystem, docName: string) {
    switch (system) {
        // Right now Starfinder is the only system so putting this at the top
        case GameSystem.Starfinder:
            return starfinderFactory(docName);
        case GameSystem.DnD5e:
        case GameSystem.Pathfinder:
        case GameSystem.Patfhinder2e:
        default:
            return undefined;
    }
}

/**
 * The system factory to retrieve a Starfinder schema
 * @param docName The name of the PDF document
 * @returns The JSON file schema if found
 */
function starfinderFactory(docName: string)  {
    return StarfinderList.find(schema => schema.title === docName);
}

// TODO: Add other gaming system factories