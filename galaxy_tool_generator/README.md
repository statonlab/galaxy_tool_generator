# Galaxy Tool Generator

**Galaxy Tool Generator** is a Drupal/Tripal module for building Galaxy tools through web interface.\

# For developing

* step 1: add component definition into the `hook_webform_component_info()` in the **.module** file, for example:

```
$components['tool'] = [
    'label' => 'tool',
    'features' => [
      'group' => TRUE,
    ],
    'file' => 'components/tool.inc',
  ];
```

* step 2: add code chunk into the `hook_form_FORM_ID_alter()` in the **.module** file, for example:

``` 
case 'tool':
      edit_component_tool($form);
      break;
```

* step 3: 

    * step 3.1: using the **components/component_template.inc** as a template to create component **.inc** file and 
        place it within **./components/** folder.
    * step 3.2: replace `component_template` with component name
    * step 3.3: fill in the `fieldset_title` argument value in the following code chunk:
    ``` 
    function _webform_render_component_template($component, $value = NULL, $filter = TRUE, $submission = NULL) {
      return get_comp   onent_render_array('component_template', $component, $fieldset_title = '');
    }
    ```
    * step 3.3: replace **xml_tag** in the following code chunk with actual **galaxy tool xml tag**:
    ``` 
    /**
     * Implement edit command function.
     */
    function edit_component_component_template(&$form) {
      unset($form['validation']);
      unset($form['display']);
    
      $form = array_merge($form, get_edit_component_base_form_elements($form, 'xml_tag'));
    
      // form field to edit attributes, available attributes for command includes:
      $form['extra']['attributes'][''] = [];
    
      // grab populated data from 'extra' column from webform_component table and
      // fill it as default values for edit component form fields.
      edit_component_form_fields_default_value($form);
    }
    ```
    * step 3.4: edit form elements for xml tag attributes.
    ``` 
    /**
     * Implement edit command function.
     */
    function edit_component_component_template(&$form) {
      unset($form['validation']);
      unset($form['display']);
    
      $form = array_merge($form, get_edit_component_base_form_elements($form, 'xml_tag'));
    
      // form field to edit attributes, available attributes for command includes:
      $form['extra']['attributes'][''] = [];
    
      // grab populated data from 'extra' column from webform_component table and
      // fill it as default values for edit component form fields.
      edit_component_form_fields_default_value($form);
    }
    ```
