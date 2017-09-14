<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_inputs_param_type_float() {
  return [
    'name' => '',
    'form_key' => NULL,
    'required' => 0,
    'pid' => 0,
    'weight' => 0,
    'extra' => [
      'attributes' => '',
      'private' => '',
    ],
  ];
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_inputs_param_type_float($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $form['inputs_param_type_float'] = [
    '#type' => 'fieldset',
    '#title' => '<b>tool > inputs > param (type: float)</b>',
    '#attributes' => ['class' => ['webform-component-fieldset']],
  ];
  $tag_value_pairs = '';
  if (!empty($component['extra']['attributes'])) {
    foreach ($component['extra']['attributes'] as $tag => $value) {
      if ($value != NULL & $tag != 'options') {
        if($tag == 'name') {
          $tag_value_pairs .= '<span style="color: #FF5666"><b>' . $tag . '</b></span>="' . $value . '" ';
        } else {
          $tag_value_pairs .= '<span style="color: #42D9C8"><b>' . $tag . '</b></span>="' . $value . '" ';
        }
      }
    }
  }
  $form['inputs_param_type_float']['inputs_param_type_float_xml'] = [
    '#markup' => '&lt;<span style="color: #19B5FE"><b>param</b></span> ' . $tag_value_pairs . '&gt;&lt;/<span style="color: #19B5FE"><b>param</b></span>&gt;',
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form['inputs_param_type_float'];
}


/**
 * edit component: inputs_param_type_float
 */
function edit_component_inputs_param_type_float(&$form) {
  unset($form['validation']);
  unset($form['display']);
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
  ];
  foreach (get_param_basetype_form_elements() as $key => $value) {
    $form['extra']['attributes'][$key] = $value;
  }

  // tag specific attributes
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('The default value for this parameter.'),
  ];
  $form['extra']['attributes']['min'] = [
    '#type' => 'textfield',
    '#title' => t('Min'),
    '#description' => t('Minimum valid parameter value.'),
  ];
  $form['extra']['attributes']['max'] = [
    '#type' => 'textfield',
    '#title' => t('Max'),
    '#description' => t('Minimum valid parameter value.'),
  ];
}