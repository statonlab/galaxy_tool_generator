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
 * The form consists of a fieldset, within the fieldset it is a markup form element
 * to display a galaxy tool XML element.
 *
 * @param $component_name the defined component name.
 * @param $component the component array.
 * @param $fieldset_title the fieldset title which reflects the XML element structure.
 * examples: 'tool > inputs', 'tool > inputs > section'
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
  ];
  $tag_value_pairs = '';
  if (!empty($component['extra']['attributes'])) {
    foreach ($component['extra']['attributes'] as $tag => $value) {
      if ($value != NULL) {
        if($tag == 'name') {
          $tag_value_pairs .= '<span style="color: #FF5666"><b>' . $tag . '</b></span>="' . $value . '" ';
        } else {
          $tag_value_pairs .= '<span style="color: #42D9C8"><b>' . $tag . '</b></span>="' . $value . '" ';
        }
      }
    }
  }
  $form['inputs_param_option']['inputs_param_option_xml'] = [
    '#markup' => '&lt;<span style="color: #19B5FE"><b>option</b></span> ' . $tag_value_pairs . '&gt;'. $component['extra']['attributes']['value'] . '&lt;/<span style="color: #19B5FE"><b>option</b></span>&gt;',
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form[$component_name];
}