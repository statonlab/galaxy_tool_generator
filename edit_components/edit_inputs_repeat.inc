<?php

/**
 * edit component: inputs_repeat
 */
function edit_component_inputs_repeat(&$form) {
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
  $form['extra']['attributes'] = [
    '#type' => 'fieldset',
    '#title' => t('Attributes'),
    '#description' => t("Tag sets that define the repeat section"),
  ];
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('The internal key used for the section.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Human readable label.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['min'] = [
    '#type' => 'select',
    '#title' => t('Min'),
    '#description' => t('The minimum number of repeat units.'),
    '#options' => drupal_map_assoc(range(0, 10)),
    '#default_value' => '0',
  ];
  $form['extra']['attributes']['max'] = [
    '#type' => 'select',
    '#title' => t('Max'),
    '#description' => t('The maximum number of repeat units.'),
    '#options' => drupal_map_assoc(range(1, 20)),
    '#default_value' => '2',
  ];
  $form['extra']['attributes']['default'] = [
    '#type' => 'select',
    '#title' => t('Default'),
    '#description' => t('The default number of repeat units.'),
    '#options' => drupal_map_assoc(range(0, 20)),
    '#default_value' => '1',
  ];
  $form['extra']['attributes']['help'] = [
    '#type' => 'textfield',
    '#title' => t('Help'),
    '#description' => t('Short help description for repeat element.'),
  ];
}