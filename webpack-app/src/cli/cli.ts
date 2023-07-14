// import { ArgumentParser } from "argparse";
// import entry from "../entry.js";

// interface Args {
//     no_schema: boolean,
//     pdf_path: string,
//     output_path: string
//   }

// // CLI argument parsing
// const parser = new ArgumentParser({ description: "Extract some images" });
// parser.add_argument('-n', '--no-schema', {
//     default: 'false',
//     action: "store_true",
//     required: false,
//     help: "If true exports all images from PDF to output folder",
// });
// parser.add_argument('pdf_path', {
//     type: 'str',
//     help: "The absolute file path to the PDF",
// });
// parser.add_argument('output_path', {
//     type: 'str',
//     help: "The output folder",
// });
// const args: Args = parser.parse_args();

// // await entry(args.pdf_path, args.output_path, args.no_schema);
// await entry(args.pdf_path, args.output_path);