<?php
// $Id$

/**
 * @file
 * Callback file for the user_auth_email module.
 */

/**
 * Helper function for autocompletion
 */
function user_auth_email_autocomplete($string = '') {
  $array = drupal_explode_tags($string);
  $last_string = trim(array_pop($array));

  $matches = array();
  if ($last_string != '') {
    $result = db_query_range("SELECT name FROM {users} WHERE LOWER(name) LIKE LOWER('%s%%')", $last_string, 0, 10);
    $prefix = count($array) ? implode(', ', $array) .', ' : '';
    while ($user = db_fetch_object($result)) {
      $matches[$prefix . $user->name] = check_plain($user->name);
    }
  }

  drupal_json($matches);
}