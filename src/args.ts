import { ArgumentParser } from "argparse";

// CLI argument parsing
const parser = new ArgumentParser({ description: "Extract some images" });
parser.add_argument('-n', '--no-schema', {
    default: 'false',
    action: "store_true",
    required: false,
    help: "If true exports all images from PDF to output folder",
});
parser.add_argument('pdf_path', {
    type: 'str',
    help: "The absolute file path to the PDF",
});
parser.add_argument('output_path', {
    type: 'str',
    help: "The output folder",
});
export const args = parser.parse_args();