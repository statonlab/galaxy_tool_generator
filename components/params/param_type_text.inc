<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_inputs_param_type_text() {
  return [
    'name' => '',
    'form_key' => NULL,
    'required' => 0,
    'pid' => 0,
    'weight' => 0,
    'extra' => [
      'attributes' => '',
    ],
  ];
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_inputs_param_type_text($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $form['inputs_param_type_text'] = [
    '#type' => 'fieldset',
    '#title' => $component['type'],
    '#attributes' => ['class' => ['webform-component-fieldset']],
  ];
  if(!empty($component['extra']['attributes'])) {
    $tag_value_pairs = '';
    foreach ($component['extra']['attributes'] as $tag=>$value) {
      if($value != null) {
        $tag_value_pairs .=  '<span style="color: #FF5666"><b>'. $tag . '</b></span>="'. $value. '" ';
      }
    }
  }
  $form['inputs_param_type_text']['inputs_param_type_text_xml'] = [
    '#markup' => '&lt;<span style="color: #19B5FE"><b>when</b></span> ' . $tag_value_pairs . '&gt;&lt;/<span style="color: #19B5FE"><b>when</b></span>&gt;',
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form['inputs_param_type_text'];
}
