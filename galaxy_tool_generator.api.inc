<?php

/**
 * Function to return an array consisting of basic element for
 * a webform default component
 *
 * @return array
 */
function get_webform_defaults_component_base_array() {
  return [
    'name' => '',
    'form_key' => NULL,
    'required' => 0,
    'pid' => 0,
    'weight' => 0,
    'extra' => [
      'private' => '',
      'attributes' => '',
    ],
  ];
}

/**
 * function to return a form for a component.
 * The form consists of a fieldset, within the fieldset it is a markup form
 * element to display a galaxy tool XML element.
 *
 * @param string $component_name the defined component name.
 * @param array $component the component array.
 * @param string $fieldset_title the fieldset title which reflects the XML
 *   element structure. examples: 'tool > inputs', 'tool > inputs > section'
 *
 * @return array
 */
function get_component_render_array($component_name, $component, $fieldset_title) {
  // create a fieldset
  // fieldset title should be a string that reflects the hierarchical structure of galaxy tool element
  $form[$component_name] = [
    '#type' => 'fieldset',
    '#title' => "<b>$fieldset_title</b>",
    '#attributes' => ['class' => ['webform-component-fieldset']],
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];
  $attribute_value_pairs = '';
  if (!empty($component['extra']['attributes'])) {
    foreach ($component['extra']['attributes'] as $attribute => $value) {
      if ($value != NULL) {
        // use red color to highlight the attribute 'name'.
        if ($attribute == 'name') {
          $attribute_value_pairs .= '<span style="color: #FF5666"><b>' . $attribute . '</b></span>="' . $value . '" ';
        }
        // use another color for all other attributes.
        else {
          // 'XML_VALUE' is not a real attribute, need to be excluded.
          if ($attribute != 'XML_VALUE') {
            $attribute_value_pairs .= '<span style="color: #42D9C8"><b>' . $attribute . '</b></span>="' . $value . '" ';
          }
        }
      }
    }
  }

  $component['extra']['attributes']['XML_VALUE'] = isset($component['extra']['attributes']['XML_VALUE']) ? $component['extra']['attributes']['XML_VALUE'] : '';
  if (in_array($component_name, [
    'tool_description',
    'tool_command',
    'tool_version_command',
  ])) {
    $markup = '&lt;<span style="color: #19B5FE"><b>' . $component['extra']['galaxy_tool_xml_tag'] . '</b></span> ' .
      $attribute_value_pairs . '&gt;![CDATA[<br/>' .
      '<pre>' .
      $component['extra']['attributes']['XML_VALUE'] .
      '</pre>' .
      '<br/>]]&gt;&lt;/<span style="color: #19B5FE"><b>' . $component['extra']['galaxy_tool_xml_tag'] . '</b></span>&gt;';
  }
  else {
    $markup = '&lt;<span style="color: #19B5FE"><b>' . $component['extra']['galaxy_tool_xml_tag'] . '</b></span> ' .
      $attribute_value_pairs . '&gt;' . $component['extra']['attributes']['XML_VALUE'] .
      '&lt;/<span style="color: #19B5FE"><b>' . $component['extra']['galaxy_tool_xml_tag'] . '</b></span>&gt;';
  }
  $form[$component_name]['xml'] = [
    '#markup' => $markup,
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form[$component_name];
}


/**
 *
 * @param string $galaxy_tool_xml_tag a xml tag the webform component is built
 *   for.
 *
 * @return array
 */
function get_edit_component_base_form_elements($form, $galaxy_tool_xml_tag) {
  $form['name'] = [
    '#type' => 'value',
    '#value' => $form['name']['#default_value'],
  ];
  $form['form_key'] = [
    '#type' => 'value',
    '#value' => $form['form_key']['#default_value'],
  ];

  $form['extra'] = [];
  $form['extra']['galaxy_tool_xml_tag'] = [
    '#type' => 'value',
    '#value' => $galaxy_tool_xml_tag,
  ];
  $form['extra']['attributes'] = [
    '#type' => 'fieldset',
    '#title' => t('Attributes'),
    '#description' => t("Tag sets for this element."),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  return $form;
}


/**
 * function to return base form elements for all kinds of param components.
 *
 * @param array $form
 * @param string $type
 *
 * @return array
 */
function get_param_type_base_form_elements($form, $type) {
  $form['extra']['attributes']['type'] = [
    '#type' => 'value',
    '#value' => $type,
  ];
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name for this element. This <span style="color: #FF5666">name</span> 
      is used as the Cheetah variable containing the user-supplied parameter 
      name in <span style="color: #FF5666">command</span> and <span style="color: #FF5666">configfile</span>
      elements. The name should not contain pipes or periods (e.g. .). Some “reserved” 
      names are <span style="color: #FF5666">REDIRECT_URL</span>, 
      <span style="color: #FF5666">DATA_URL</span>, <span style="color: #FF5666">GALAXY_URL</span>.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['argument'] = [
    '#type' => 'textfield',
    '#title' => t('Argument'),
    '#description' => t('If the parameter reflects just one command line argument 
      of a certain tool, this tag should be set to that particular argument. 
      It is rendered in parenthesis after the help section, and it will create 
      the name attribute from the argument attribute by stripping the dashes (e.g. 
      if <span style="color: #FF5666">argument="--sensitive"</span> then 
      <span style="color: #FF5666">name="sensitive"</span> is implicit).'),
  ];
  $form['extra']['attributes']['label'] = [
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#description' => t('The attribute value will be displayed on the tool page 
      as the label of the form field (<span style="color: #FF5666">label="Sort Query"</span>).	'),
  ];
  $form['extra']['attributes']['help'] = [
    '#type' => 'textarea',
    '#title' => t('Help'),
    '#description' => t('Short bit of text, rendered on the tool form just below 
      the associated field to provide information about the field. Find the 
      Intergalactic Utilities Commision suggested best practices for this element here.'),
  ];
  $form['extra']['attributes']['optional'] = [
    '#type' => 'radios',
    '#title' => t('Optional'),
    '#description' => t('If <span style="color: #FF5666">false</span>, 
        parameter must have a value. Defaults to “false”.'),
    '#options' => drupal_map_assoc([
      'False',
      'True',
    ]),
    '#default_value' => 'False',
  ];
  $form['extra']['attributes']['refresh_on_change'] = [
    '#type' => 'radios',
    '#title' => t('Refresh on change'),
    '#description' => t('Force a reload of the tool panel when the value of this 
      parameter changes to allow <span style="color: #FF5666">code</span> file processing. See deprecation-like notice 
      for <span style="color: #FF5666">code</span> blocks.'),
    '#options' => drupal_map_assoc([
      'False',
      'True',
    ]),
  ];
  return $form;
}

/**
 * recursive function to build galaxy tool config file from webform components.
 *
 * @param array $galaxy_webform
 */
function build_galaxy_tool_xml_element(array $component_tree, DOMDocument &$domdocument) {
  if (isset($component_tree['extra'])) {
    // create element
    $DOMElem = $domdocument->createElement($component_tree['extra']['galaxy_tool_xml_tag']);
    foreach ($component_tree['extra']['attributes'] as $attribute => $value) {
      // create attribute
      $DOMAttr = $domdocument->createAttribute($attribute);
      $DOMAttr->value = $value;
    }

    if (isset($component_tree['children'])) {
      foreach ($component_tree['children'] as $child) {
        // append child element.
        $new_node = $domdocument->appendChild($DOMElem);
        // create element
        $new_node->createElement($child['extra']['galaxy_tool_xml_tag']);
        foreach ($child['extra']['attributes'] as $attribute => $value) {
          // create attribute
          $DOMAttr = $new_node->createAttribute($attribute);
          $DOMAttr->value = $value;
        }
      }
    }
  }
}

class WebformComponentIterator extends ArrayIterator implements RecursiveIterator {

  public function getChildren() {
    // TODO: Implement getChildren() method.
    $component = $this->current();
    return new WebformComponentIterator($component['children']);
  }

  public function hasChildren() {
    // TODO: Implement hasChildren() method.
    $component = $this->current();
    return !empty($component['children']);
  }
}

