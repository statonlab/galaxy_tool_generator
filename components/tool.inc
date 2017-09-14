<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool', $component, 'tool');
}

/**
 * Implement edit command function.
 */
function edit_component_tool(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['id'] = [
    '#type' => 'textfield',
    '#title' => t('Tool ID'),
    '#description' => t('Must be unique across all tools; should be lowercase and 
      contain only letters, numbers, and underscores. It allows for tool versioning 
      and metrics of the number of times a tool is used, among other things. 
      Find the Intergalactic Utilities Commission suggested best practices for this element '.
      l('here', 'https://planemo.readthedocs.io/en/latest/standards/docs/best_practices/tool_xml.html#tool-ids')),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('This string is what is displayed as a hyperlink in the tool menu. 
      Find the Intergalactic Utilities Commision suggested best practices for this element '.
      l('here', 'https://planemo.readthedocs.io/en/latest/standards/docs/best_practices/tool_xml.html#tool-ids'))
  ];
}