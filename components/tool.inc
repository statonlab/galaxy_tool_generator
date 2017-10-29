<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('tool', $component, 'tool');
}

/**
 * Implement edit command function.
 */
function edit_component_tool(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'tool'));

    // form field to edit attributes, available attributes for command includes:
    $form['extra']['attributes']['id'] = [
        '#type' => 'textfield',
        '#title' => t('Tool ID'),
        '#description' => t('Must be unique across all tools; should be lowercase and 
      contain only letters, numbers, and underscores. It allows for tool versioning 
      and metrics of the number of times a tool is used, among other things. 
      Find the Intergalactic Utilities Commission suggested best practices for this element ' .
            l('here', 'https://planemo.readthedocs.io/en/latest/standards/docs/best_practices/tool_xml.html#tool-ids')),
        '#required' => TRUE,
    ];
    $form['extra']['attributes']['name'] = [
        '#type' => 'textfield',
        '#title' => t('Name'),
        '#description' => t('This string is what is displayed as a hyperlink in the tool menu. 
      Find the Intergalactic Utilities Commision suggested best practices for this element ' .
            l('here', 'https://planemo.readthedocs.io/en/latest/standards/docs/best_practices/tool_xml.html#tool-ids')),
        '#required' => TRUE,
    ];
    $form['extra']['attributes']['version'] = [
        '#type' => 'textfield',
        '#title' => t('Version'),
        '#description' => t('This string defaults to <span style="color: #FF5666">1.0.0</span> 
        if it is not included in the tag. It allows for tool versioning and should be 
        increased with each new version of the tool. Find the Intergalactic Utilities 
        Commission suggested best practices for this element ' .
            l('here', 'https://planemo.readthedocs.io/en/latest/standards/docs/best_practices/tool_xml.html#tool-versions')),
        '#default_value' => '1.0.0',
    ];
    $form['extra']['attributes']['hidden'] = [
        '#type' => 'radios',
        '#title' => t('Hidden'),
        '#description' => t('Allows for tools to be loaded upon server startup, 
      but not displayed in the tool menu. This attribute should be applied in 
      the toolbox configuration instead and so should be considered deprecated.'),
        '#options' => drupal_map_assoc([
            'False',
            'True',
        ]),
    ];
    $form['extra']['attributes']['display_interface'] = [
        '#type' => 'radios',
        '#title' => t('Display interface'),
        '#description' => t('Disable the display the tool’s graphical tool form 
      by setting this to <span style="color: #FF5666">false</span>.'),
        '#options' => drupal_map_assoc([
            'False',
            'True',
        ]),
    ];
    $form['extra']['attributes']['tool_type'] = [
        '#type' => 'radios',
        '#title' => t('Tool type'),
        '#description' => t('Allows for certain framework functionality to be performed 
      on certain types of tools. Normal tools that execute typical command-line 
      jobs do not need to specify this, special kinds of tools such as ' .
            l('Data Source', 'https://galaxyproject.org/admin/internals/data-sources/') .
            ' and ' .
            l('Data Manager', 'https://galaxyproject.org/admin/tools/data-managers/') .
            'tools should set this to have values such as <span style="color: #FF5666">data_source</span> 
      or <span style="color: #FF5666">manage_data</span>.'),
        '#options' => drupal_map_assoc([
            'data_source',
            'manage_data',
        ]),
    ];
    $form['extra']['attributes']['profile'] = [
        '#type' => 'textfield',
        '#title' => t('Profile'),
        '#description' => t('This string specified the minimum Galaxy version that 
      should be required to run this tool. Certain legacy behaviors such as 
      using standard error content to detect errors instead of exit code are 
      disabled automatically if profile is set to any version newer than 
      <span style="color: #FF5666">16.01</span>, such as <span style="color: #FF5666">16.04</span>.'),
    ];
    $form['extra']['attributes']['workflow_compatible'] = [
        '#type' => 'radios',
        '#title' => t('Workflow compatible'),
        '#description' => t('This attribute indicates if this tool is usable within 
      a workflow (defaults to <span style="color: #FF5666">true</span> for normal 
      tools and <span style="color: #FF5666">false</span> for data sources).'),
        '#options' => drupal_map_assoc([
            'True',
            'False',
        ]),
    ];
    $form['extra']['attributes']['URL_method'] = [
        '#type' => 'radios',
        '#title' => t('URL method'),
        '#description' => t('Only used if <span style="color: #FF5666">tool_type</span> 
        attribute value is <span style="color: #FF5666">data_source</span> - this 
        attribute defines the HTTP request method to use when communicating with an 
        external data source application (the default is <span style="color: #FF5666">get</span>).'),
        '#options' => drupal_map_assoc([
            'get',
            'put',
        ]),
    ];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}