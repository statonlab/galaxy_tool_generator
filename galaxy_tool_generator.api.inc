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
 * @param $component_name the defined component name.
 * @param $component the component array.
 * @param $fieldset_title the fieldset title which reflects the XML element
 *   structure. examples: 'tool > inputs', 'tool > inputs > section'
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
  $tag_value_pairs = '';
  if (!empty($component['extra']['attributes'])) {
    foreach ($component['extra']['attributes'] as $tag => $value) {
      if ($value != NULL) {
        // use red color to highlight the attribute 'name'.
        if ($tag == 'name') {
          $tag_value_pairs .= '<span style="color: #FF5666"><b>' . $tag . '</b></span>="' . $value . '" ';
        }
        // use another color for all other attributes.
        else {
          // 'XML_VALUE' is not a real attribute, need to be excluded.
          if ($tag != 'XML_VALUE') {
            $tag_value_pairs .= '<span style="color: #42D9C8"><b>' . $tag . '</b></span>="' . $value . '" ';
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
    $markup = '&lt;<span style="color: #19B5FE"><b>' . $component_name . '</b></span> ' .
      $tag_value_pairs . '&gt;![CDATA[<br/>' .
      '<pre>' .
      $component['extra']['attributes']['XML_VALUE'] .
      '</pre>' .
      '<br/>]]&gt;&lt;/<span style="color: #19B5FE"><b>' . $component_name . '</b></span>&gt;';
  }
  else {
    $markup = '&lt;<span style="color: #19B5FE"><b>' . $component_name . '</b></span> ' .
      $tag_value_pairs . '&gt;' . $component['extra']['attributes']['XML_VALUE'] .
      '&lt;/<span style="color: #19B5FE"><b>' . $component_name . '</b></span>&gt;';
  }
  $form[$component_name]['xml'] = [
    '#markup' => $markup,
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form[$component_name];
}


/**
 * @return array
 */
function get_edit_component_base_form_elements($form) {
  $form['name'] = [
    '#type' => 'value',
    '#value' => $form['name']['#default_value'],
  ];
  $form['form_key'] = [
    '#type' => 'value',
    '#value' => $form['form_key']['#default_value'],
  ];

  $form['extra'] = [];
  $form['extra']['attributes'] = [
    '#type' => 'fieldset',
    '#title' => t('Attributes'),
    '#description' => t("Tag sets for this element."),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  return $form;
}
