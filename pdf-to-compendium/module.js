// import "./scripts/entry.js";

class FormClass {
    static ID = 'pdf-to-compendium';
    static FLAGS = {};
    static TEMPLATES = `modules/${this.ID}/templates/index.hbs`;
    static log(force, ...args) {
        console.log(this.ID, '|', ...args);
    }
}
// localhost:30000/modules/pdf-to-compendium/scripts/entry.js
// https://foundryvtt.wiki/en/development/guides/understanding-form-applications
class MySubmenuApplicationClass extends FormApplication {
    constructor(exampleOption) {
        super();
        this.exampleOption = exampleOption;
    }

    static get defaultOptions() {
        return mergeObject(super.defaultOptions, {
            classes: ['form'],
            popOut: true,
            template: `./modules/pdf-to-compendium/index.html`,
            id: 'my-form-application',
            title: 'My FormApplication',
            closeOnSubmit: false,
            submitOnChange: true,
            submitOnClose: true,
        });
    }

    getData() {
        // Send data to the template
        return {
            msg: this.exampleOption,
            color: 'red',
        };
    }

    activateListeners(html) {
        super.activateListeners(html);

        html.find('.file-input').on('change', (event) => {
           const files = event.target.files;
           
           console.log(`PDF to Compendium | [FORM] Selected files: ${files}`);
        });
    }

    async _updateObject(event, formData) {
        console.log(formData);
    }
};

Hooks.once('init', async function () {
    console.log(`PDF to Compendium | [INIT] Initializing the module`);

    // console.log(`PDF to Compendium | [TEST] ${test()}`);
    console.log(
        `__________________________________________________________
        *******  *******   ********         **                    
        /**////**/**////** /**/////         /**                    
        /**   /**/**    /**/**             ******  ******          
        /******* /**    /**/*******       ///**/  **////**         
        /**////  /**    /**/**////          /**  /**   /**         
        /**      /**    ** /**              /**  /**   /**         
        /**      /*******  /**              //** //******          
        //       ///////   //                //   //////           
         ********                                **                
        /**/////                                /**         **   **
        /**        ******  **   ** *******      /** ****** //** ** 
        /*******  **////**/**  /**//**///**  ******//**//*  //***  
        /**////  /**   /**/**  /** /**  /** **///** /** /    /**   
        /**      /**   /**/**  /** /**  /**/**  /** /**      **    
        /**      //****** //****** ***  /**//******/***     **     
        //        //////   ////// ///   //  ////// ///     //      
        ===========================================================`);

    // console.log(fs.constants.F_OK);

    game.settings.registerMenu("myModule", "mySettingsMenu", {
        name: "My Settings Submenu",
        label: "Settings Menu Label",      // The text label used in the button
        hint: "A description of what will occur in the submenu dialog.",
        icon: "fas fa-bars",               // A Font Awesome icon used in the submenu button
        type: MySubmenuApplicationClass,   // A FormApplication subclass which should be created
        restricted: true                   // Restrict this submenu to gamemaster only?
    });

});

Hooks.once('devModeReady', ({ registerPackageDebugFlag}) => {
    registerPackageDebugFlag(FormClass.ID);
})