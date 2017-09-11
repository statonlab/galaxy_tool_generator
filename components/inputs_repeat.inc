<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_inputs_repeat() {
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
function _webform_render_inputs_repeat($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $form['inputs_repeat'] = [
    '#type' => 'fieldset',
    '#title' => '<b>tool > inputs > repeat</b>',
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
  $form['inputs_repeat']['inputs_repeat_xml'] = [
    '#markup' => '&lt;<span style="color: #19B5FE"><b>repeat</b></span> ' . $tag_value_pairs . '&gt;&lt;/<span style="color: #19B5FE"><b>repeat</b></span>&gt;',
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form['inputs_repeat'];
}
