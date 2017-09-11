<?php

/**
 * edit component: description
 */
function edit_component_description(&$form) {
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
  $form['extra']['parent'] = [
    '#type' => 'select',
    '#title' => 'Parent',
    '#description' => t('The parent component of this component'),
    '#options' => drupal_map_assoc([
      'inputs',
      'tool',
    ]),
    '#required' => TRUE,
  ];
  $form['extra']['description_value'] = [
    '#type' => 'textarea',
    '#default_value' => '',
    '#title' => t('Description'),
    '#description' => t("The value is displayed in the tool menu immediately 
          following the hyperlink for the tool (based on the <code>name</code> attribute of 
          the <code>&lt;tool&gt;</code> tag set)."),
    '#required' => TRUE,
  ];
}