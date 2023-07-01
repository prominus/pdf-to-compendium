# PDF to Compendium Importer - Dev Notes

```{note}
Developing for the Starfinder system, but could potentially be useful for other Foundry VTT systems.
```

## Build Instructions

**TODO**

## High-Level Concept for this module

This module will have dialog in a world settings to upload a PDF. Once a PDF is selected and an import is kicked off, first the PDF will be verified, then it will be kicked off to the workers.

There will be several worker types running concurrently. These workers will be:

* Image Extractor - This worker shall mine each page of the PDF for images. Images in a PDF are held in XObjects, have a name of `/Im#` and a Subset of `/Image`.  When extracted this worker will name the value `Page#_Im#` and store on the heap. To optimize the process this worker will not care what the images contain. Testing with one extractor seemed relatively fast, but splitting to several workers extracting from multiple pages will likely be faster.

* Artwork Handler - This worker shall grab the extracted images from the heap, and generate the actor and token. This worker will use a schemato look up images from the memory heap. There likely can be several of these workers as one extracted image likely correlates to one character.

* Compendium worker -  When an actor and token image are created for a character this worker shall update the world compendium. This might just be something to wait for the other types of workers finish their task then start the compendium updating. This will also likely look over the schema, verify the new actor/token exists, then update that section of the compendium.

## Assumptions

The Foundry VTT Starfinder system seems pretty thorough in text and stats, so this importer will focus on image importing for now.

The official Paizo Manuals are static in nature so we will know how many images to expect. As such, the memory needed can be allocated up front and freed at the end. The schema should provide how much memory needs to be allocated for the selected PDF. 

The allocated memory should be a map (dictionary) to look up extracted images based on the `Page#_Im#` title. As each image will be a different size, that portion in the map can point to a vector in heap.

The schemas will be a json or equivalent database file from the `system_mapping/sfrpg` folder. This is filesystem is laid out as such in case another gaming system can use this module, and others generate schemas for it. 😊 

An item in the schema should have fields like `ID`, `official_name`, and `pdf_name` where:

* ID correlates to the character id in the system compendium database.
* official_name correlates to the character's name in the system compendium database. This shall be used to name the actor and token images along with linking said images in the compendium.
* pdf_name correlates to the `Page#_Im#` that will be used to search the memory heap.

An example would be:

    "rYqcQSfW9JNZvrgu": [ // ID
        {
            "official_name": "Goblin Zaperator, Space",
            "pdf_name": "Page56_Im1"
        }
    ]

Once an extracted image is placed in heap it should be immutable. Generated actors and tokens should not replace this image.

Generated actors and tokens shall be saved in the directory `C:\Users\Magenta\AppData\Local\FoundryVTT\Data` in a folder whose name coincides with the Official manual.

Actors will just be the original image with a title `<name_of_actor>.actor.webp`

Tokens will have the image altered, merged with `default-starfinder-frame` from the `artwork` folder, and saved as `<name_of_token>.token.webp`

An example of image names would be:

* goblin_zaperator_space.actor.webp
* goblin_zaperator_space.token.webp

This module shall not alter or edit the directory `C:\Users\Magenta\AppData\Local\FoundryVTT\Data\systems`.  All images will tied to compendiums using hooks in the Foundry VTT API.