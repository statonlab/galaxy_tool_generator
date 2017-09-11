<?php

/**
 * edit component: version_command
 */
function edit_component_version_command(&$form) {
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
  $form['extra']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Element name'),
    '#description' => t('The name of element in the Galaxy tool configure file.'),
    '#required' => TRUE,
  ];
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
  $form['extra']['version_command_file'] = [
    '#name' => 'version_command_file',
    '#type' => 'file',
    '#title' => t('Version command file'),
    '#description' => t("A <code>sh</code> script file. The script will be placed
        into the <code>tool-&gtversion_command</code> and will be run to get the
        tools's version string."),
    '#required' => TRUE,
  ];
}