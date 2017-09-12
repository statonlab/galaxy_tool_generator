<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_inputs_param_option() {
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
function _webform_render_inputs_param_option($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $form['inputs_param_option'] = [
    '#type' => 'fieldset',
    '#title' => '<b>tool > inputs > param > option</b>',
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
  $form['inputs_param_option']['inputs_param_option_xml'] = [
    '#markup' => '&lt;<span style="color: #19B5FE"><b>option</b></span> ' . $tag_value_pairs . '&gt;'. $component['extra']['attributes']['value'] . '&lt;/<span style="color: #19B5FE"><b>option</b></span>&gt;',
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form['inputs_param_option'];
}


/**
 * edit component: inputs_param_option
 */
function edit_component_inputs_param_option(&$form) {
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

  // element specific attributes
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('The value of the corresponding variable when used the 
      Cheetah template. Also the value that should be used in building test cases 
      and used when building requests for the API.	'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['select'] = [
    '#type' => 'radios',
    '#title' => t('Select'),
    '#description' => t('A boolean parameter indicating if the corresponding 
      option is selected by default (the default is false).	'),
    '#options' => drupal_map_assoc([
      'True',
      'False',
    ]),
  ];
}