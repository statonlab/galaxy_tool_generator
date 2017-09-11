<?php

/**
 * @file
 * version_command component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_inputs() {
  return [
    'name' => '',
    'form_key' => NULL,
    'required' => 0,
    'pid' => 0,
    'weight' => 0,
    'extra' => [
      'parent' => '',
      'attributes' => '',
    ],
  ];
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_inputs($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $form['inputs'] = [
    '#type' => 'fieldset',
    '#title' => $component['type'],
    '#attributes' => ['class' => ['webform-component-fieldset']],
  ];
  if(!empty($component['extra']['attributes'])) {
    $tag_value_pairs = '';
    foreach ($component['extra']['attributes'] as $tag=>$value) {
      if($value != null) {
        $tag_value_pairs .=  $tag . '="'. $value. '" ';
      }
    }
  }
  $form['inputs']['inputs_xml'] = [
    '#markup' => '&lt;inputs ' . $tag_value_pairs . '&gt;&lt;/inputs&gt;',
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form['inputs'];
}



