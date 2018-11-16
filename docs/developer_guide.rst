Developer Guide
================


**Galaxy Tool Generator** consists of two Drupal modules: `galaxy_tool_generator_ui` and `galaxy_tool_generator`. The
`galaxy_tool_generator_ui` is responsible for the UI design of the web application. The `galaxy_tool_generator`
creates a list of web form components that map to the Galaxy Tool XML components defined
`here <https://docs.galaxyproject.org/en/release_18.09/dev/schema.html>`_.
Developers can contribute to this application by creating new web form components for
newly added XML components by the Galaxy project team. This guide assumes you know the basic of Drupal module development
and are familiar with the `Drupal Form API <https://www.drupal.org/docs/7/api/form-api>`_.


Develop Web Form Component
--------------------------

Step 0: choose a good component name
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The component name should reflect the XML component structure. Below are a few examples showing the relationship
between web component name and XML component:

* XML component: ``tool``   –   webform component name: ``tool``
* XML component: ``tool->requirements``  –  webform component name: ``tool_requirements``
* XML component: ``tool->requirements->requirement``    –   webform component name: ``tool->requirements->requirement``


Step 1: define a new webform component
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Add component definition into the `hook_webform_component_info()` in the **.module** file, for example:

.. code-block:: php

    $components['tool'] = [
        'label' => 'COMPONENT_NAME',
        'features' => [
          'group' => TRUE,
        ],
        'file' => 'components/COMPONENT_NAME.inc',
      ];



Step 2: declare a form for editing webform component attributes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Add a case entry to the `galaxy_tool_generator_form_webform_component_edit_form_alter()` in the **.module** file, for example:

.. code-block:: php

    case 'COMPONENT_NAME':
          edit_component_COMPONENT_NAME($form);
          break;


You will need to replace `COMPONENT_NAME` in the code block with the actual component name.



Step 3: define the form for editing webform component attributes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Step 3.1: utilize ``component_template.inc`` file
"""""""""""""""""""""""""""""""""""""""""""""""""

* Using the **components/component_template.inc** as a template to create component a **COMPONENT_NAME.inc**
file and place it within **./components/** folder. Replace ``COMPONENT_NAME`` in the file name with actual component name.

* Replace `component_template` with component name
* Fill in the `fieldset_title` argument value in the following code chunk:

.. code-block:: php

    function _webform_render_component_template($component, $value = NULL, $filter = TRUE, $submission = NULL) {
      return get_comp   onent_render_array('component_template', $component, $fieldset_title = '');
    }


Step 3.2: specify Galaxy Tool XML tag
"""""""""""""""""""""""""""""""""""""""""""""""""

Replace **xml_tag** in the following code chunk with actual **Galaxy Tool XML tag**:


.. code-block:: php

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


Step 3.3: edit form elements for xml tag attributes.
"""""""""""""""""""""""""""""""""""""""""""""""""

Below is the form definition function for creating the form of editing webform components. Edit this function
to create form elements for each XML attributes.

.. code-block:: php

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
