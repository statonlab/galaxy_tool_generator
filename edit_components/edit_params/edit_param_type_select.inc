<?php

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
  foreach (get_param_basetype_form_elements() as $key=>$value) {
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
    '#description' => t('Allow multiple valus to be selected. Valid with data and 
      select parameters.	'),
    '#options' => drupal_map_assoc([
      'True',
      'False',
    ]),
    '#default_value' => 'True',
  ];
  $form['extra']['attributes']['options'] = [
    '#type' => 'textarea',
    '#title' => t('Options'),
    '#description' => t('<b>Key-value pairs MUST be specified as "safe_key|Some readable option"</b>. 
        Use of only alphanumeric characters and underscores is recommended in keys. The first <b>key-value</b>
        will always be the default selected option.'),
    '#required' => TRUE,
  ];
}