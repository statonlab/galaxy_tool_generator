<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_inputs_param_type_select() {
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
function _webform_render_inputs_param_type_select($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $form['inputs_param_type_select'] = [
    '#type' => 'fieldset',
    '#title' => '<b>tool > inputs > param (type: select)</b>',
    '#attributes' => ['class' => ['webform-component-fieldset']],
  ];
  if (!empty($component['extra']['attributes'])) {
    $tag_value_pairs = '';
    foreach ($component['extra']['attributes'] as $tag => $value) {
      if ($value != NULL & $tag != 'options') {
        $tag_value_pairs .= '<span style="color: #FF5666"><b>' . $tag . '</b></span>="' . $value . '" ';
      }
    }
  }
  $form['inputs_param_type_select']['inputs_param_type_select_xml'] = [
    '#markup' => '&lt;<span style="color: #19B5FE"><b>param</b></span> ' . $tag_value_pairs . '&gt;&lt;/<span style="color: #19B5FE"><b>param</b></span>&gt;',
  ];
  $options = [];
  foreach (preg_split('/[\s]+/', $component['extra']['attributes']['options']) as $option) {
    $key = explode('|', $option)[0];
    $options[$key] = explode('|', $option)[1];
  }
  $form['inputs_param_type_select']['inputs_param_type_select_field'] = [
    '#type' => 'radios',
    '#title' => isset($component['extra']['attributes']['label']) ? $component['extra']['attributes']['label'] : $component['name'],
    '#description' => isset($component['extra']['attributes']['help']) ? $component['extra']['attributes']['help'] : '',
    '#options' => $options,
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form['inputs_param_type_select'];
}
