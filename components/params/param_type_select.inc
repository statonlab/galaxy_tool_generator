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

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form['inputs_param_type_select'];
}


/**
 * edit component: inputs_param_type_select
 */
function edit_component_inputs_param_type_select(&$form) {
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

  // text param specific attributes
  $form['extra']['attributes']['select'] = [
    '#type' => 'value',
    '#value' => 'select',
  ];
  $form['extra']['attributes']['data_ref'] = [
    '#type' => 'textfield',
    '#title' => t('Data ref'),
    '#description' => t('Only valid if type attribute value is select or data_column. 
      Used with select lists whose options are dynamically generated based on 
      certain metadata attributes of the dataset upon which this parameter 
      depends (usually but not always the tool’s input dataset).	'),
  ];
  $form['extra']['attributes']['display'] = [
    '#type' => 'radios',
    '#title' => t('Display'),
    '#description' => t('This attribute is used only if type attribute value is 
      select - render a select list as a set of check boxes or radio buttons. 
      Defaults to a drop-down menu select list.	'),
    '#options' => drupal_map_assoc([
      'checkboxes',
      'radios',
    ]),
  ];
  $form['extra']['attributes']['multiple'] = [
    '#type' => 'radios',
    '#title' => t('Multiple'),
    '#description' => t('Allow multiple values to be selected. Valid with data and 
      select parameters.	'),
    '#options' => drupal_map_assoc([
      'True',
      'False',
    ]),
    '#default_value' => 'True',
  ];
}