<?php

/**
 * @file
 * version_command component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_version_command() {
  return [
    'name' => '',
    'form_key' => NULL,
    'required' => 0,
    'pid' => 0,
    'weight' => 0,
    'extra' => [
      'attributes' => '',
      'version_command' => '',
      'private' => '',
    ],
  ];
}



/**
 * Implements _webform_render_version_command().
 */
function _webform_render_version_command($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $form['version_command'] = [
    '#type' => 'fieldset',
    '#title' => '<b>tool > version_command</b>',
    '#attributes' => ['class' => ['webform-component-fieldset']],
  ];
  $tag_value_pairs = '';
  if (!empty($component['extra']['attributes'])) {
    foreach ($component['extra']['attributes'] as $tag => $value) {
      if ($value != NULL) {
        if($tag == 'name') {
          $tag_value_pairs .= '<span style="color: #FF5666"><b>' . $tag . '</b></span>="' . $value . '" ';
        } else {
          $tag_value_pairs .= '<span style="color: #42D9C8"><b>' . $tag . '</b></span>="' . $value . '" ';
        }
      }
    }
  }
  $form['version_command']['version_command_xml'] = [
    '#markup' => '&lt;<span style="color: #19B5FE"><b>version_command</b></span> ' . $tag_value_pairs . '&gt;'. $component['extra']['version_command'] . '&lt;/<span style="color: #19B5FE"><b>version_command</b></span>&gt;',
  ];

  // returning $form breaks components-grouping. it has to return $form['inputs']
  return $form['version_command'];
}

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
  $form['extra']['attributes'] = [
    '#type' => 'fieldset',
    '#title' => t('Attributes'),
    '#description' => t("Tag sets for this element."),
  ];
  $form['extra']['attributes']['interpreter'] = [
    '#type' => 'textfield',
    '#title' => t('Attributes'),
    '#description' => t('Deprecated: Prefix the version command with an interpreter 
        and the tool directory in order to execute a script shipped with the tool. 
        It is better to just use &lt;interpreter&gt; $__tool_directory__/&lt;script_name&gt;.'),
  ];
  $form['extra']['version_command'] = [
    '#type' => 'textarea',
    '#title' => t('Version command'),
    '#description' => t('Specifies the command to be run in order to get the 
      tool’s version string. The resulting value will be found in the “Info” 
      field of the history dataset.'),
  ];
}