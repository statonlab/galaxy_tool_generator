<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_type_data()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_type_data($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('tool_inputs_param_type_data', $component, 'tool > inputs > param (type: data)');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_type_data(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'param'));

    // form field to edit attributes, available attributes includes:
    $form = array_merge($form, get_param_type_base_form_elements($form, 'data'));
    $form['extra']['attributes']['format'] = [
        '#type' => 'textfield',
        '#title' => t('Format'),
        '#description' => t('Only if <span style="color: #FF5666">type</span> attribute 
        value is <span style="color: #FF5666">data</span> or <span style="color: #FF5666">data_collection</span> - the 
        list of supported data formats is contained in the ' .
            l('/config/datatypes_conf.xml.sample', 'https://github.com/galaxyproject/galaxy/blob/dev/config/datatypes_conf.xml.sample') .
            ' file. Use the file extension.'),
    ];
    $form['extra']['attributes']['multiple'] = [
        '#type' => 'radios',
        '#title' => t('Multiple'),
        '#description' => t('Allow multiple valus to be selected. Valid with 
      <span style="color: #FF5666">data</span> and <span style="color: #FF5666">select</span> parameters.'),
        '#options' => drupal_map_assoc([
            'True',
            'False',
        ]),
    ];

}