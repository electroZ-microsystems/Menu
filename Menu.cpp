#include "Menu.h"

/*


███╗   ███╗███████╗███╗   ██╗██╗   ██╗██╗████████╗███████╗███╗   ███╗
████╗ ████║██╔════╝████╗  ██║██║   ██║██║╚══██╔══╝██╔════╝████╗ ████║
██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║██║   ██║   █████╗  ██╔████╔██║
██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║██║   ██║   ██╔══╝  ██║╚██╔╝██║
██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝██║   ██║   ███████╗██║ ╚═╝ ██║
╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝   ╚═╝   ╚══════╝╚═╝     ╚═╝

*/
bool MenuItem::update(menu_event_t event) {
    return false; // nothing to do - just return false
};

void MenuItem::getText(char* buffer) {
    strcpy(buffer, name);
}

/*


███████╗██╗   ██╗██████╗ ███╗   ███╗███████╗███╗   ██╗██╗   ██╗██╗████████╗███████╗███╗   ███╗
██╔════╝██║   ██║██╔══██╗████╗ ████║██╔════╝████╗  ██║██║   ██║██║╚══██╔══╝██╔════╝████╗ ████║
███████╗██║   ██║██████╔╝██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║██║   ██║   █████╗  ██╔████╔██║
╚════██║██║   ██║██╔══██╗██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║██║   ██║   ██╔══╝  ██║╚██╔╝██║
███████║╚██████╔╝██████╔╝██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝██║   ██║   ███████╗██║ ╚═╝ ██║
╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝   ╚═╝   ╚══════╝╚═╝     ╚═╝
*/
bool SubMenuItem::update(menu_event_t event) {
    if (submenu!=NULL) {
        parent->goSubmenu(submenu);
    }
    return false; // return false to leave activation state
};


/*


 █████╗  ██████╗████████╗██╗ ██████╗ ███╗   ██╗███╗   ███╗███████╗███╗   ██╗██╗   ██╗██╗████████╗███████╗███╗   ███╗
██╔══██╗██╔════╝╚══██╔══╝██║██╔═══██╗████╗  ██║████╗ ████║██╔════╝████╗  ██║██║   ██║██║╚══██╔══╝██╔════╝████╗ ████║
███████║██║        ██║   ██║██║   ██║██╔██╗ ██║██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║██║   ██║   █████╗  ██╔████╔██║
██╔══██║██║        ██║   ██║██║   ██║██║╚██╗██║██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║██║   ██║   ██╔══╝  ██║╚██╔╝██║
██║  ██║╚██████╗   ██║   ██║╚██████╔╝██║ ╚████║██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝██║   ██║   ███████╗██║ ╚═╝ ██║
╚═╝  ╚═╝ ╚═════╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝   ╚═╝   ╚══════╝╚═╝     ╚═╝
*/
bool ActionMenuItem::update(menu_event_t event) {
    if (callback!=NULL) {
        bool returnValue= callback(callbackArgument);
        if (!returnValue) requestRedraw();
        return returnValue;
    }
    requestRedraw();
    return false; // nothing to do - just return false
};

/*


██████╗  █████╗ ██████╗  █████╗ ███╗   ███╗███╗   ███╗███████╗███╗   ██╗██╗   ██╗██╗████████╗███████╗███╗   ███╗
██╔══██╗██╔══██╗██╔══██╗██╔══██╗████╗ ████║████╗ ████║██╔════╝████╗  ██║██║   ██║██║╚══██╔══╝██╔════╝████╗ ████║
██████╔╝███████║██████╔╝███████║██╔████╔██║██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║██║   ██║   █████╗  ██╔████╔██║
██╔═══╝ ██╔══██║██╔══██╗██╔══██║██║╚██╔╝██║██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║██║   ██║   ██╔══╝  ██║╚██╔╝██║
██║     ██║  ██║██║  ██║██║  ██║██║ ╚═╝ ██║██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝██║   ██║   ███████╗██║ ╚═╝ ██║
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝   ╚═╝   ╚══════╝╚═╝     ╚═╝
*/

bool ParamMenuItem::update(menu_event_t event) {
    if (event==MENU_LEAVE) {requestRedraw(); return false;} // nothing to do - just return false
    //if (event==    MENU_SELECT) {requestRedraw(); return false;} // nothing to do - just return false
    if (event==MENU_UP) {parameter->increment();    requestRedraw();}
    if (event==MENU_DOWN) {parameter->decrement();  requestRedraw();}
    if (event==MENU_SELECT)
    {
       Serial.print("Action on ParamMenuIten\n");
       Serial.println(parent->getCurrentSubmenu()->isActivated());
       //delay(400);
       //if (parent->activated)
    }
    // check analog input
    if (knob!=NULL) {
        if (knob->hasChanged()) {
            parameter->setScaledValue(knob->getValue());
            requestRedraw();
        }
    }
    return true;
};

void ParamMenuItem::getText(char* buffer) {
    strcpy(buffer, name);
    strcat(buffer, "=");
    char valueBuffer[5];
    parameter->getValueAsString(valueBuffer);
    strcat(buffer, valueBuffer);
    return buffer;
}

/*
███╗   ███╗███████╗███╗   ██╗██╗   ██╗
████╗ ████║██╔════╝████╗  ██║██║   ██║
██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║
██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║
██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝
╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ 
*/
MenuItem* Menu::getCurrentItem() {
    return items[selectedItem];
  };

MenuItem* Menu::getItem(uint8_t index) {
    if ((index>=0)&&(index<maxCount)) 
      return items[index];
    else return NULL;
  };
  
uint8_t Menu::getSelectedItem() {return selectedItem;};
  
uint8_t Menu::getScrollOffset() {return scrollOffset;};

Menu* Menu::getParent() {
    return parent;
  }
void Menu::setParent(Menu* newParent) {
    parent=newParent;
  }

Menu* Menu::getCurrentSubmenu() {
    return currentSubmenu;
  }

void Menu::goSubmenu(Menu* submenu) {
    currentSubmenu=submenu;
    if (parent!=NULL) parent->goSubmenu(submenu); // recursively go to root, to set current submenu everywhere
    submenu->setParent(this);
  }

void Menu::leaveSubmenu() {
    currentSubmenu=currentSubmenu->getParent();
    if (currentSubmenu==NULL) currentSubmenu=this;
    currentSubmenu->redraw = true;
  }
  
void Menu::goNext() {
    if (selectedItem < maxCount-1) selectedItem++;
    if (selectedItem-scrollOffset > 3) scrollOffset=selectedItem - 3;
  };
  
void Menu::goPrevious() {
    if (selectedItem>0)  selectedItem--;
    if (selectedItem<scrollOffset) scrollOffset=selectedItem;
  };

void Menu::goLast() {
    selectedItem= maxCount-1;
    if (selectedItem-scrollOffset>3) scrollOffset=selectedItem-3;
    scrollOffset=selectedItem-3;
  };

void Menu::goFirst() {
    selectedItem=0;
    if (selectedItem<scrollOffset) scrollOffset=selectedItem;
  };


/*
███╗   ███╗███████╗███╗   ██╗██╗   ██╗        ███╗   ██╗ █████╗ ██╗   ██╗██╗ ██████╗  █████╗ ████████╗███████╗███╗   ███╗███████╗███╗   ██╗██╗   ██╗
████╗ ████║██╔════╝████╗  ██║██║   ██║        ████╗  ██║██╔══██╗██║   ██║██║██╔════╝ ██╔══██╗╚══██╔══╝██╔════╝████╗ ████║██╔════╝████╗  ██║██║   ██║
██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║        ██╔██╗ ██║███████║██║   ██║██║██║  ███╗███████║   ██║   █████╗  ██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║
██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║        ██║╚██╗██║██╔══██║╚██╗ ██╔╝██║██║   ██║██╔══██║   ██║   ██╔══╝  ██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║
██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝        ██║ ╚████║██║  ██║ ╚████╔╝ ██║╚██████╔╝██║  ██║   ██║   ███████╗██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝
╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝         ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ 
*/
MenuItem* Menu::navigateMenu(menu_event_t event) {
    currentSubmenu->redraw=false; 
    if (currentSubmenu->activated) 
    {
        #ifdef BUTTON_POLICY_3
        if (event == MENU_SELECT)
        {
           //leaveSubmenu();
           currentSubmenu->redraw=true;
           currentSubmenu->activated = false;
           return currentSubmenu->getCurrentItem();
        }
        #endif   
           
        currentSubmenu->activated = currentSubmenu->getCurrentItem()->update(event);
        currentSubmenu->redraw    = currentSubmenu->getCurrentItem()->needsRedraw(); 
        return currentSubmenu->getCurrentItem();
    } 
    else 
    {
        currentSubmenu->redraw=true; 
        //if (event > 0)
        //   Serial.println(String("maxCount=")+String(currentSubmenu->maxCount)+ String(" selected=")+String(currentSubmenu->selectedItem));
        switch(event) {
            case MENU_UP:
                #ifdef ROLLOVER 
                if (currentSubmenu->selectedItem == 0) currentSubmenu->goLast();
                else 
                #endif 
                   currentSubmenu->goPrevious();
                
            break;
            case MENU_DOWN:
                  
                #ifdef ROLLOVER
                if (currentSubmenu->selectedItem == (currentSubmenu->maxCount -1))
                    currentSubmenu->goFirst();    
                
                else
                #endif
                   currentSubmenu->goNext();
            break;
            case MENU_SELECT:

                #ifdef BUTTON_POLICY_3
                if(String(currentSubmenu->getCurrentItem()->getName()) == String("back"))
                {
                   leaveSubmenu();
                   currentSubmenu->redraw=true;
                   return NULL;
                }     
                #endif 

                if (currentSubmenu->activated)
{
                   leaveSubmenu();
                   currentSubmenu->redraw=true;
                   currentSubmenu->activated = false;
                   return NULL;
                }                        
 
                if (currentSubmenu->getCurrentItem()!=NULL) {
                    // set parent to ensure correct return
                    currentSubmenu->getCurrentItem()->parent = currentSubmenu;
                    //Serial.println("SELECT ...");
                    //Serial.println(currentSubmenu->getCurrentItem()->getName());
                    //Serial.println(String("before activated ->")+String(currentSubmenu->activated));
                    currentSubmenu->activated = currentSubmenu->getCurrentItem()->update(event);
                    //Serial.println(String("after activated ->")+String(currentSubmenu->activated));
                    currentSubmenu->getCurrentItem()->select();

                    return currentSubmenu->getCurrentItem();
                }
            break;
            case MENU_LEAVE:
                leaveSubmenu();
                currentSubmenu->redraw=true; 
            break;
            default:
               currentSubmenu->redraw=false; // nothing has changed
            break;
        }
        
    }
    return NULL;
}


