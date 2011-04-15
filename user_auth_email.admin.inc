<?php
// $Id$

/**
 * Admin Settings form
 */
function user_auth_email_admin_settings() {
  $form['user_auth_email_default'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send email to website\'s email adress.'),
    '#description' => t('Deaktivate the option if you don\'t want to send the "waiting for approval email" to the website\'s email adress.'),
    '#default_value' => variable_get('user_auth_email_default', TRUE),
  );

  $form['user_auth_email_users'] = array(
    '#type' => 'textfield',
    '#title' => t('User list'),
    '#description' => t('Enter a comma separated list of users that should receive a "waiting for approval email".'),
    '#autocomplete_path' => 'user_auth_email/autocomplete',
    '#default_value' => variable_get('user_auth_email_users', ''),
  );
  
  $options = user_roles(TRUE);
  $form['user_auth_email_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Roles'),
    '#description' => t('Choose those roles from their users should receive a "waiting for approval email".'),
    '#default_value' => variable_get('user_auth_email_roles', array()),
    '#options' => $options,
  );

  return system_settings_form($form);
}