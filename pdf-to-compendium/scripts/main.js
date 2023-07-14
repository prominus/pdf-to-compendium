import entry from "./entry";
document.querySelector('#app').innerHTML = `
<form class="flexcol" id="form" autocomplete="off" onsubmit="event.preventDefault();">
<nav class="sheet-tabs tabs" data-group="primary">
  <a data-tab="summary">Summary</a>
  <a data-tab="sfs">SFS</a>
  <a data-tab="alien-archive">Alien Archive</a>
</nav>

<hr />

<section class="starfinderpdftofoundry-content">
  <div class="tab browser" data-group="primary" data-tab="summary">
    <p>
      You may import unmodified PDFs from Paizo only. For personal use
      only.
    </p>
    <p>
      This will create actors/scenes/journal entries in this world.
      Importing flip mats/interactive maps will update maps for all
      matching scenes in the world.
    </p>
    <p>
      Tokens will be placed in worlds for supported modules (indicated
      with a star). This is an early access feature and may not work in
      all cases.
    </p>

  <div class="tab browser" data-group="primary" data-tab="sfs">
    <div class="supported-modules-container"></div>
  </div>
</section>

<hr />

<div class="form-group">
  <p>Upload multiple files with the file dialog or by dragging and dropping filed onto the dashed region.</p>
  <label class="button" for="fileElem">Select Some Files</label>
  <input type="file" id="fileElem" multiple accept="*.pdf">
  <input id="submitButton" type="submit" value="Submit">
</div>
<!-- <div class="form-group">
        <input type="checkbox" name="consent" id="consent" checked>
        <label for="consent">I consent to send telemetry data about the usage of this module</label>
    </div> -->
</form>
`;
const submitButton = document.getElementById("submitButton");
const fileDialog = document.getElementById("fileElem");
export function test() {
    return "Here is a value from entry.ts";
}
if (submitButton != null && fileDialog != null) {
    submitButton.addEventListener("click", (ev) => {
        ev.preventDefault();
        console.log(test());
        if (fileDialog.files != null && fileDialog.files.length > 0) {
            const file_arr = Array.from(fileDialog.files);
            file_arr.forEach(async (file) => {
                console.log("File:", file);
                const pdf_data = await entry(file, 'output');
                console.log("Data:");
                console.log(pdf_data);
            });
        }
        else {
            console.log("Could not submit any PDFs.");
        }
    });
}
//# sourceMappingURL=main.js.map