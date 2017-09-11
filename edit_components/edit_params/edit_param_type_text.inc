<?php

require drupal_get_path('module', 'galaxy_tool_generator') . '/edit_components/edit_params/edit_param_basetype.inc';

/**
 * edit component: inputs_param_type_text
 */
function edit_component_inputs_param_type_text(&$form) {
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
  $form['extra']['attributes']['type'] = [
    '#type' => 'value',
    '#value' => 'text',
  ];
  $form['extra']['attributes']['area'] = [
    '#type' => 'radios',
    '#title' => t('Area'),
    '#description' => t('Boolean indicating if this should be rendered as a one 
      line text box (if false) or a multi-line text area (if true).	'),
    '#options' => drupal_map_assoc([
      'False',
      'True',
    ]),
  ];
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('The default value for this parameter.	'),
  ];
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('Used only if type attribute value is text. To create 
      a multi-line text box add an area="True" attribute to the param tag. 
      This can be one dimensional (e.g. size="40") or two dimensional 
      (e.g. size="5x25").	'),
  ];
}