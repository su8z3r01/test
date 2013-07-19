<?php



function banner_quantity_admin(){
	
  //$form = array();
  

  $form['#tree'] = TRUE;
  
  

  
  $form['layers_quantity'] = array(
  	'#type' => 'textfield',
  	'#name' => 'layers_quantity',
  	'#default_value' => variable_get('layers_quantity', 0),
  	'#title' => 'Layers Quantity',
  	'#size' => 10,
  	'#required' => TRUE,
	'#weight' => 0,
  );
  
  $slides_quantity = variable_get('layers_quantity');  
  
  if($slides_quantity>0){
		
	   $form['slides_style'] = array(
	    '#name' => 'slides_style',
        '#type' => 'select',
        '#title' => t('Style'),
        '#options' => styles_options_list(),     
	    '#default_value' => variable_get('slides_style'),
        '#description' => t('Set the to apply to slides'),
	    '#multiple' => false,
	    '#requred' => false,	    
       );
  
       for($i=1; $i<=$slides_quantity; $i++){
         $form['layers_' . $i] = array(
           '#type' => 'fieldset', 
           '#title' => t('Layerslide Layer #' . $i), 
           '#weight' => $i, 
           '#collapsible' => TRUE,
           '#collapsed' => true,
         );	

         $form['layers_' . $i]['settings'] = array(
           '#type' => 'fieldset', 
           '#title' => t('Layer #' . $i . ' settings'), 
           '#weight' => 0, 
           '#collapsible' => TRUE,
           '#collapsed' => true,
         );			 
		 
		 $form['layers_' . $i]['settings']['slider_slideDirection'] = array(
         	'#type' => 'select',
         	'#name' => 'slider_direction',
	       '#options' => array(
             'left' => 'Left',
             'right' => 'Right',  
	         'top' => 'Top',
	         'bottom' => 'Bottom',
	       ),
         	'#default_value' => variable_get('slider_direction', 'right'),
         	'#title' => 'slideDirection ',
	       '#description' => t('Slide direction. New layers sliding FROM(!) this direction.'),
         );
		 
         $form['layers_' . $i]['settings']['slider_slideDelay'] = array(
         	'#type' => 'textfield',
         	'#name' => 'slider_slideDelay',
         	'#default_value' => variable_get('slider_slideDelay', 4000),
         	'#title' => 'slideDelay',
	       '#description' => t('LayerSlider will begin with this layer. (Numeric, millisecs)'),
         	'#size' => 10,
         ); 
		 
         $form['layers_' . $i]['settings']['slider_durationIn'] = array(
         	'#type' => 'textfield',
         	'#name' => 'slider_durationIn',
         	'#default_value' => variable_get('slider_durationIn', 1000),
         	'#title' => 'durationIn',
	       '#description' => t('Duration of the slide-in animation. (Numeric, millisecs)'),
         	'#size' => 10,
         );   
         
         $form['layers_' . $i]['settings']['slider_durationOut'] = array(
         	'#type' => 'textfield',
         	'#name' => 'slider_durationOut',
         	'#default_value' => variable_get('slider_durationOut', 1000),
         	'#title' => 'durationOut',
	       '#description' => t('Duration of the slide-out animation. (Numeric, millisecs)'),
         	'#size' => 10,
         );  
         
         $form['layers_' . $i]['settings']['slider_easingIn'] = array(
         	'#type' => 'select',
         	'#name' => 'slider_easingIn',
	        '#options' => get_easing(),
         	'#default_value' => variable_get('slider_easingIn', 'easeInOutQuint'),
         	'#title' => 'easingIn',
	       '#description' => t('Easing (type of transition) of the slide-in animation.'),
         ); 
         
         $form['layers_' . $i]['settings']['slider_easingOut'] = array(
         	'#type' => 'select',
         	'#name' => 'slider_easingOut',
	       '#options' => get_easing(),
         	'#default_value' => variable_get('slider_easingOut', 'easeInOutQuint'),
         	'#title' => 'easingOut',
	       '#description' => t('Easing (type of transition) of the slide-in animation.'),
         ); 
         
         $form['layers_' . $i]['settings']['slider_delayIn'] = array(
         	'#type' => 'textfield',
         	'#name' => 'slider_delayIn',
         	'#default_value' => variable_get('slider_delayIn', 0),
         	'#title' => 'delayIn',
	       '#description' => t('Delay time of the slide-in animation. (Numeric, millisecs)'),
         	'#size' => 10,
         ); 
         
         $form['layers_' . $i]['settings']['slider_delayOut'] = array(
         	'#type' => 'textfield',
         	'#name' => 'slider_delayOut',
         	'#default_value' => variable_get('slider_delayOut', 0),
         	'#title' => 'delayOut',
	       '#description' => t('Delay time of the slide-out animation. (Numeric, millisecs)'),
         	'#size' => 10,
         );  		 
		 /*********************/
		 
		 /*
		 $form['layers_' . $i]['ls_sublayer'] = array(
		   '#type' => 'fieldset', 
           '#title' => t('Layerslide sublayer #' ), 
           '#weight' => 0, 
           '#collapsible' => TRUE,
           '#collapsed' => true,
		 );*/
		 
		 
		 /*
		 $form['layers_' . $i]['ls_sublayer']['settings'] = array(
		   '#type' => 'fieldset', 
           '#title' => t('Sublayer Settings' ), 
           '#weight' => 0, 
           '#collapsible' => TRUE,
           '#collapsed' => true,
		 );
		 */
         /**
		 $form['layers_' . $i]['ls_sublayer']['settings']['slide_image_' . $i] = array(
           '#type' => 'managed_file',
           '#title' => t('Slide Image #@number', array('@number' => $i)),
           '#description' => t('Allowed extensions: gif png jpg jpeg.'),
           '#default_value' => variable_get('slide_image_' . $i),
           '#size' => 10,
           '#description' => '',
           '#required' => FALSE,
           '#upload_location' => 'public://layerslider_slides',
           '#theme' => 'layerslider_banner_test',
           '#upload_validators' => array(
           'file_validate_extensions' => array('gif png jpg jpeg'),
           'file_validate_size' => array('MAX_FILE_SIZE' * 1200 * 300),
           ), 
		 );
		 
		 **/
		 

		 
		 if ($form_state['layers_' . $i]['ls_sublayer']){
			for ($j = 1; $j <= $form['layers_' . $i]['ls_sublayer']; $j++) {
		      $form['layers_' . $i]['ls_sublayer']['settings'] = array(
		        '#type' => 'fieldset', 
                '#title' => t('Sublayer Settings'), 
                '#weight' => 0, 
                '#collapsible' => TRUE,
                '#collapsed' => true,
		      );
			  $form['layers_' . $i]['ls_sublayer']['settings'][$j]['slide_image_' . $j] = array(
                '#type' => 'managed_file',
                '#title' => t('Slide Image #@number', array('@number' => $i)),
                '#description' => t('Allowed extensions: gif png jpg jpeg.'),
                '#default_value' => variable_get('slide_image_' . $i),
                '#size' => 10,
                '#description' => '',
                '#required' => FALSE,
                '#upload_location' => 'public://layerslider_slides',
                '#theme' => 'layerslider_banner_test',
                '#upload_validators' => array(
                'file_validate_extensions' => array('gif png jpg jpeg'),
                'file_validate_size' => array('MAX_FILE_SIZE' * 1200 * 300),
                ), 
		      );
			}
		 }
		 
         $form['layers_' . $i]['sublayer'] = array(
           '#type' => 'container',
           '#tree' => TRUE,
           '#prefix' => '<div id="sublayer">',
           '#suffix' => '</div>',
         );
		 
         $form['layers_' . $i]['add_sublayer'] = array(
          '#type' => 'button',
          '#value' => t('Aggiungi un nuovo sottolivello'),
          '#href' => '',
          '#ajax' => array(
            'callback' => 'add_another_sublayer',
            'wrapper' => 'sublayer',
           ),
         );		 
		 
       }	
  }
  
  $form['#submit'][] = 'layerslider_banner_admin_form_submit';
  
 
  
  return system_settings_form($form);
	
}

function layerslider_banner_admin_form_submit($form, $form_state){
	
	variable_set('quantity', variable_get('slides_number'));
}

function add_another_sublayer(){
	return "test";
}