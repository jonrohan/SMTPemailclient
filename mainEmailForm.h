#pragma once
#include "aboutDialog.h"
#include "newMessageForm.h"
#include "loginForm.h"
#include <cstdlib>
#include <string>

extern "C++"
{
	int getNumberOfNewItems();
	String* getPop3Message(int);
	void closePop3();
	
}


namespace SMTPemailclient
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	///<summary>
	///AUTHOR: Jon Rohan
	///TITLE: SMTP/POP3 email client
	///DATE: 3.29.2005
	///PURPOSE: The purpose of this class is to handle all the operations of the user
	///			and to provide an easy to use display to the user
	///</summary>
	public __gc class mainEmailForm : public System::Windows::Forms::Form
	{	
	public:
		mainEmailForm(void)
		{
			InitializeComponent();
			
			
		}
  
	protected:
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}
	private: System::Windows::Forms::MainMenu *  mainMenu;


	private: System::Windows::Forms::MenuItem *  menuItem3;

	private: System::Windows::Forms::MenuItem *  menuItem6;



	private: System::Windows::Forms::Panel *  treeViewPanel;

	private: System::Windows::Forms::Panel *  panel1;
	private: System::Windows::Forms::ListView *  listView1;

	private: System::Windows::Forms::Panel *  panel2;
	private: System::Windows::Forms::RichTextBox *  richTextBox1;
	private: System::Windows::Forms::StatusBar *  statusBar1;
	private: System::Windows::Forms::Panel *  panel3;
	private: System::Windows::Forms::ColumnHeader *  fromColumn;
	private: System::Windows::Forms::ColumnHeader *  subjectColumn;
	private: System::Windows::Forms::ColumnHeader *  dateColumn;
	private: System::Windows::Forms::ColumnHeader *  columnHeader1;

	private: System::Windows::Forms::MenuItem *  exitMenuItem;
	private: System::Windows::Forms::Label *  label1;
	private: System::Windows::Forms::Panel *  panel4;
	public: System::Windows::Forms::StatusBarPanel *  statusBarPanel1;

	private: System::ComponentModel::IContainer *  components;
	private: System::String* from;
	private: System::String* date;
	private: System::String* subject;
	private: System::Windows::Forms::ListView *  trashMailbox;
	private: System::Windows::Forms::ColumnHeader *  columnHeader2;
	private: System::Windows::Forms::ColumnHeader *  columnHeader3;
	private: System::Windows::Forms::ColumnHeader *  columnHeader4;
	private: System::Windows::Forms::ColumnHeader *  columnHeader5;
	private: System::Windows::Forms::MenuItem *  fileMenuItem;
	private: System::Windows::Forms::MenuItem *  newMessageMenuItem;
	private: System::Windows::Forms::MenuItem *  checkMainMenuItem;
	private: System::Windows::Forms::MenuItem *  helpMenuItem;
	private: System::Windows::Forms::MenuItem *  aboutMenuItem;
	private: System::Windows::Forms::TreeView *  mailboxFolders;
	private: System::Windows::Forms::ImageList *  mailMessageImageList;
	private: System::String* body;
	public: bool pop3enabled;
	private:
		void InitializeComponent(void)
				{
					this->components = new System::ComponentModel::Container();
					System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(SMTPemailclient::mainEmailForm));
					this->mainMenu = new System::Windows::Forms::MainMenu();
					this->fileMenuItem = new System::Windows::Forms::MenuItem();
					this->newMessageMenuItem = new System::Windows::Forms::MenuItem();
					this->menuItem3 = new System::Windows::Forms::MenuItem();
					this->checkMainMenuItem = new System::Windows::Forms::MenuItem();
					this->menuItem6 = new System::Windows::Forms::MenuItem();
					this->exitMenuItem = new System::Windows::Forms::MenuItem();
					this->helpMenuItem = new System::Windows::Forms::MenuItem();
					this->aboutMenuItem = new System::Windows::Forms::MenuItem();
					this->treeViewPanel = new System::Windows::Forms::Panel();
					this->mailboxFolders = new System::Windows::Forms::TreeView();
					this->panel1 = new System::Windows::Forms::Panel();
					this->panel4 = new System::Windows::Forms::Panel();
					this->listView1 = new System::Windows::Forms::ListView();
					this->columnHeader1 = new System::Windows::Forms::ColumnHeader();
					this->fromColumn = new System::Windows::Forms::ColumnHeader();
					this->subjectColumn = new System::Windows::Forms::ColumnHeader();
					this->dateColumn = new System::Windows::Forms::ColumnHeader();
					this->mailMessageImageList = new System::Windows::Forms::ImageList(this->components);
					this->trashMailbox = new System::Windows::Forms::ListView();
					this->columnHeader2 = new System::Windows::Forms::ColumnHeader();
					this->columnHeader3 = new System::Windows::Forms::ColumnHeader();
					this->columnHeader4 = new System::Windows::Forms::ColumnHeader();
					this->columnHeader5 = new System::Windows::Forms::ColumnHeader();
					this->label1 = new System::Windows::Forms::Label();
					this->panel2 = new System::Windows::Forms::Panel();
					this->richTextBox1 = new System::Windows::Forms::RichTextBox();
					this->statusBar1 = new System::Windows::Forms::StatusBar();
					this->statusBarPanel1 = new System::Windows::Forms::StatusBarPanel();
					this->panel3 = new System::Windows::Forms::Panel();
					this->treeViewPanel->SuspendLayout();
					this->panel1->SuspendLayout();
					this->panel4->SuspendLayout();
					this->panel2->SuspendLayout();
					(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->statusBarPanel1))->BeginInit();
					this->panel3->SuspendLayout();
					this->SuspendLayout();
					// 
					// mainMenu
					// 
					System::Windows::Forms::MenuItem* __mcTemp__1[] = new System::Windows::Forms::MenuItem*[2];
					__mcTemp__1[0] = this->fileMenuItem;
					__mcTemp__1[1] = this->helpMenuItem;
					this->mainMenu->MenuItems->AddRange(__mcTemp__1);
					// 
					// fileMenuItem
					// 
					this->fileMenuItem->Index = 0;
					System::Windows::Forms::MenuItem* __mcTemp__2[] = new System::Windows::Forms::MenuItem*[5];
					__mcTemp__2[0] = this->newMessageMenuItem;
					__mcTemp__2[1] = this->menuItem3;
					__mcTemp__2[2] = this->checkMainMenuItem;
					__mcTemp__2[3] = this->menuItem6;
					__mcTemp__2[4] = this->exitMenuItem;
					this->fileMenuItem->MenuItems->AddRange(__mcTemp__2);
					this->fileMenuItem->Text = S"File";
					// 
					// newMessageMenuItem
					// 
					this->newMessageMenuItem->Index = 0;
					this->newMessageMenuItem->Shortcut = System::Windows::Forms::Shortcut::CtrlN;
					this->newMessageMenuItem->Text = S"New Message";
					this->newMessageMenuItem->Click += new System::EventHandler(this, menuItem2_Click);
					// 
					// menuItem3
					// 
					this->menuItem3->Index = 1;
					this->menuItem3->Text = S"-";
					// 
					// checkMainMenuItem
					// 
					this->checkMainMenuItem->Index = 2;
					this->checkMainMenuItem->Text = S"Check for New Mail";
					this->checkMainMenuItem->Click += new System::EventHandler(this, menuItem5_Click);
					// 
					// menuItem6
					// 
					this->menuItem6->Index = 3;
					this->menuItem6->Text = S"-";
					// 
					// exitMenuItem
					// 
					this->exitMenuItem->Index = 4;
					this->exitMenuItem->Text = S"Exit";
					this->exitMenuItem->Click += new System::EventHandler(this, menuItem7_Click);
					// 
					// helpMenuItem
					// 
					this->helpMenuItem->Index = 1;
					System::Windows::Forms::MenuItem* __mcTemp__3[] = new System::Windows::Forms::MenuItem*[1];
					__mcTemp__3[0] = this->aboutMenuItem;
					this->helpMenuItem->MenuItems->AddRange(__mcTemp__3);
					this->helpMenuItem->Text = S"Help";
					// 
					// aboutMenuItem
					// 
					this->aboutMenuItem->Index = 0;
					this->aboutMenuItem->Text = S"About";
					this->aboutMenuItem->Click += new System::EventHandler(this, menuItem9_Click);
					// 
					// treeViewPanel
					// 
					this->treeViewPanel->Controls->Add(this->mailboxFolders);
					this->treeViewPanel->Dock = System::Windows::Forms::DockStyle::Left;
					this->treeViewPanel->DockPadding->All = 3;
					this->treeViewPanel->Location = System::Drawing::Point(0, 0);
					this->treeViewPanel->Name = S"treeViewPanel";
					this->treeViewPanel->Size = System::Drawing::Size(184, 505);
					this->treeViewPanel->TabIndex = 0;
					// 
					// mailboxFolders
					// 
					this->mailboxFolders->Dock = System::Windows::Forms::DockStyle::Fill;
					this->mailboxFolders->ImageIndex = -1;
					this->mailboxFolders->Location = System::Drawing::Point(3, 3);
					this->mailboxFolders->Name = S"mailboxFolders";
					System::Windows::Forms::TreeNode* __mcTemp__4[] = new System::Windows::Forms::TreeNode*[2];
					__mcTemp__4[0] = new System::Windows::Forms::TreeNode(S"Inbox");
					__mcTemp__4[1] = new System::Windows::Forms::TreeNode(S"Trash");
					this->mailboxFolders->Nodes->AddRange(__mcTemp__4);
					this->mailboxFolders->Scrollable = false;
					this->mailboxFolders->SelectedImageIndex = -1;
					this->mailboxFolders->ShowLines = false;
					this->mailboxFolders->Size = System::Drawing::Size(178, 499);
					this->mailboxFolders->TabIndex = 0;
					this->mailboxFolders->AfterSelect += new System::Windows::Forms::TreeViewEventHandler(this, mailboxFolders_AfterSelect);
					// 
					// panel1
					// 
					this->panel1->Controls->Add(this->panel4);
					this->panel1->Controls->Add(this->label1);
					this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
					this->panel1->DockPadding->All = 3;
					this->panel1->Location = System::Drawing::Point(184, 0);
					this->panel1->Name = S"panel1";
					this->panel1->Size = System::Drawing::Size(608, 200);
					this->panel1->TabIndex = 0;
					// 
					// panel4
					// 
					this->panel4->Controls->Add(this->listView1);
					this->panel4->Controls->Add(this->trashMailbox);
					this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
					this->panel4->Location = System::Drawing::Point(3, 35);
					this->panel4->Name = S"panel4";
					this->panel4->Size = System::Drawing::Size(602, 162);
					this->panel4->TabIndex = 2;
					// 
					// listView1
					// 
					this->listView1->Activation = System::Windows::Forms::ItemActivation::OneClick;
					this->listView1->Alignment = System::Windows::Forms::ListViewAlignment::Left;
					this->listView1->CheckBoxes = true;
					System::Windows::Forms::ColumnHeader* __mcTemp__5[] = new System::Windows::Forms::ColumnHeader*[4];
					__mcTemp__5[0] = this->columnHeader1;
					__mcTemp__5[1] = this->fromColumn;
					__mcTemp__5[2] = this->subjectColumn;
					__mcTemp__5[3] = this->dateColumn;
					this->listView1->Columns->AddRange(__mcTemp__5);
					this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
					this->listView1->FullRowSelect = true;
					this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
					this->listView1->HideSelection = false;
					this->listView1->LabelWrap = false;
					this->listView1->Location = System::Drawing::Point(0, 0);
					this->listView1->Name = S"listView1";
					this->listView1->Size = System::Drawing::Size(602, 162);
					this->listView1->StateImageList = this->mailMessageImageList;
					this->listView1->TabIndex = 0;
					this->listView1->View = System::Windows::Forms::View::Details;
					this->listView1->MouseUp += new System::Windows::Forms::MouseEventHandler(this, listView1_MouseUp);
					this->listView1->SelectedIndexChanged += new System::EventHandler(this, listView1_SelectedIndexChanged);
					this->listView1->ItemCheck += new System::Windows::Forms::ItemCheckEventHandler(this, listView1_ItemChecked);
					this->listView1->KeyDown += new System::Windows::Forms::KeyEventHandler(this, listView1_KeyPressEvent);
					// 
					// columnHeader1
					// 
					this->columnHeader1->Text = S"";
					this->columnHeader1->Width = 24;
					// 
					// fromColumn
					// 
					this->fromColumn->Text = S"From";
					this->fromColumn->Width = 171;
					// 
					// subjectColumn
					// 
					this->subjectColumn->Text = S"Subject";
					this->subjectColumn->Width = 293;
					// 
					// dateColumn
					// 
					this->dateColumn->Text = S"Date";
					this->dateColumn->Width = 109;
					// 
					// mailMessageImageList
					// 
					this->mailMessageImageList->ColorDepth = System::Windows::Forms::ColorDepth::Depth32Bit;
					this->mailMessageImageList->ImageSize = System::Drawing::Size(19, 19);
					this->mailMessageImageList->ImageStream = (__try_cast<System::Windows::Forms::ImageListStreamer *  >(resources->GetObject(S"mailMessageImageList.ImageStream")));
					this->mailMessageImageList->TransparentColor = System::Drawing::Color::Transparent;
					// 
					// trashMailbox
					// 
					this->trashMailbox->Activation = System::Windows::Forms::ItemActivation::OneClick;
					this->trashMailbox->Alignment = System::Windows::Forms::ListViewAlignment::Left;
					this->trashMailbox->CheckBoxes = true;
					System::Windows::Forms::ColumnHeader* __mcTemp__6[] = new System::Windows::Forms::ColumnHeader*[4];
					__mcTemp__6[0] = this->columnHeader2;
					__mcTemp__6[1] = this->columnHeader3;
					__mcTemp__6[2] = this->columnHeader4;
					__mcTemp__6[3] = this->columnHeader5;
					this->trashMailbox->Columns->AddRange(__mcTemp__6);
					this->trashMailbox->Dock = System::Windows::Forms::DockStyle::Fill;
					this->trashMailbox->FullRowSelect = true;
					this->trashMailbox->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
					this->trashMailbox->HideSelection = false;
					this->trashMailbox->LabelWrap = false;
					this->trashMailbox->Location = System::Drawing::Point(0, 0);
					this->trashMailbox->Name = S"trashMailbox";
					this->trashMailbox->Size = System::Drawing::Size(602, 162);
					this->trashMailbox->StateImageList = this->mailMessageImageList;
					this->trashMailbox->TabIndex = 1;
					this->trashMailbox->View = System::Windows::Forms::View::Details;
					this->trashMailbox->Visible = false;
					// 
					// columnHeader2
					// 
					this->columnHeader2->Text = S"";
					this->columnHeader2->Width = 24;
					// 
					// columnHeader3
					// 
					this->columnHeader3->Text = S"From";
					this->columnHeader3->Width = 171;
					// 
					// columnHeader4
					// 
					this->columnHeader4->Text = S"Subject";
					this->columnHeader4->Width = 293;
					// 
					// columnHeader5
					// 
					this->columnHeader5->Text = S"Date";
					this->columnHeader5->Width = 109;
					// 
					// label1
					// 
					this->label1->BackColor = System::Drawing::SystemColors::AppWorkspace;
					this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
					this->label1->Dock = System::Windows::Forms::DockStyle::Top;
					this->label1->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
					this->label1->ForeColor = System::Drawing::SystemColors::Window;
					this->label1->Location = System::Drawing::Point(3, 3);
					this->label1->Name = S"label1";
					this->label1->Size = System::Drawing::Size(602, 32);
					this->label1->TabIndex = 1;
					this->label1->Text = S"  View Recieved";
					this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
					// 
					// panel2
					// 
					this->panel2->Controls->Add(this->richTextBox1);
					this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
					this->panel2->DockPadding->All = 3;
					this->panel2->Location = System::Drawing::Point(184, 200);
					this->panel2->Name = S"panel2";
					this->panel2->Size = System::Drawing::Size(608, 305);
					this->panel2->TabIndex = 1;
					// 
					// richTextBox1
					// 
					this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
					this->richTextBox1->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
					this->richTextBox1->Location = System::Drawing::Point(3, 3);
					this->richTextBox1->Name = S"richTextBox1";
					this->richTextBox1->Size = System::Drawing::Size(602, 299);
					this->richTextBox1->TabIndex = 0;
					this->richTextBox1->Text = S"";
					// 
					// statusBar1
					// 
					this->statusBar1->Location = System::Drawing::Point(0, 505);
					this->statusBar1->Name = S"statusBar1";
					System::Windows::Forms::StatusBarPanel* __mcTemp__7[] = new System::Windows::Forms::StatusBarPanel*[1];
					__mcTemp__7[0] = this->statusBarPanel1;
					this->statusBar1->Panels->AddRange(__mcTemp__7);
					this->statusBar1->ShowPanels = true;
					this->statusBar1->Size = System::Drawing::Size(792, 32);
					this->statusBar1->TabIndex = 2;
					// 
					// statusBarPanel1
					// 
					this->statusBarPanel1->AutoSize = System::Windows::Forms::StatusBarPanelAutoSize::Spring;
					this->statusBarPanel1->Width = 776;
					// 
					// panel3
					// 
					this->panel3->Controls->Add(this->panel2);
					this->panel3->Controls->Add(this->panel1);
					this->panel3->Controls->Add(this->treeViewPanel);
					this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
					this->panel3->Location = System::Drawing::Point(0, 0);
					this->panel3->Name = S"panel3";
					this->panel3->Size = System::Drawing::Size(792, 505);
					this->panel3->TabIndex = 3;
					// 
					// mainEmailForm
					// 
					this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
					this->ClientSize = System::Drawing::Size(792, 537);
					this->Controls->Add(this->panel3);
					this->Controls->Add(this->statusBar1);
					this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
					this->Menu = this->mainMenu;
					this->MinimumSize = System::Drawing::Size(150, 100);
					this->Name = S"mainEmailForm";
					this->Text = S"Simple SMTP/POP3 Mail Client";
					this->Load += new System::EventHandler(this, mainEmailForm_Load);
					this->treeViewPanel->ResumeLayout(false);
					this->panel1->ResumeLayout(false);
					this->panel4->ResumeLayout(false);
					this->panel2->ResumeLayout(false);
					(__try_cast<System::ComponentModel::ISupportInitialize *  >(this->statusBarPanel1))->EndInit();
					this->panel3->ResumeLayout(false);
					this->ResumeLayout(false);

				}	




	
	///<summary>
	/// This is an event handler for when the form loads
	///</summary>
private: System::Void mainEmailForm_Load(System::Object *  sender, System::EventArgs *  e)
		 {
				loginForm * login = new loginForm();
				login->ShowDialog();
				this->pop3enabled = login->getpop3enabled();
				login->Close();

				this->checkForMail();
		 }
	///<summary>
	/// This is an event handler for when the user clicks the exit menuItem
	///</summary>
private: System::Void menuItem7_Click(System::Object *  sender, System::EventArgs *  e)
		 {
			 exit(0);
		 }
	///<summary>
	/// This is an event handler for when the user clicks the about menuItem
	///</summary>
private: System::Void menuItem9_Click(System::Object *  sender, System::EventArgs *  e)
		 {
			 aboutDialog * about = new aboutDialog();
			 about->ShowDialog();
		 }
///<summary>
	/// This is an event handler for when the user clicks the new message menuItem
	///</summary>
private: System::Void menuItem2_Click(System::Object *  sender, System::EventArgs *  e)
		 {
			 newMessageForm * message = new newMessageForm();
			 message->Show();
		 }
	///<summary>
	/// This is an event handler for when the index changes in the listView
	///</summary>
private: System::Void listView1_SelectedIndexChanged(System::Object *  sender, System::EventArgs *  e)
		 {
			 ListView::SelectedListViewItemCollection *c = new ListView::SelectedListViewItemCollection(this->listView1);
			 int i;
			 for(i=0; i<c->Count;i++)
			 {
				ListViewItem * item = new ListViewItem();
				item = c->get_Item(i);
				if(item->Checked)
					item->Checked = false;
				this->richTextBox1->set_Text(item->SubItems->get_Item(4)->get_Text());
			 }
		 }
	///<summary>
	/// This is an event handler for when the index changes in the listView
	///</summary>
private: System::Void listView1_MouseUp(System::Object *  sender, System::Windows::Forms::MouseEventArgs *  e)
		 {
			 this->updateStatusBar();
		 }
///<summary>
	/// This is an event handler for when an item is checked in the listView
	///</summary>
private: System::Void listView1_ItemChecked(System::Object * sender, System::Windows::Forms::ItemCheckEventArgs * e)
		 {
			 int index = e->get_Index();
			 ListViewItem * item = new ListViewItem();
			 item = this->listView1->Items->get_Item(index);
			 if(!item->Checked)
				 item->set_Font(new System::Drawing::Font(item->Font,Bold));
			 else
				 item->set_Font(new System::Drawing::Font(item->Font,Regular));
		 }
		
		///<summary>
	/// This is used to get the total number of items in the inbox
	///</summary>
		int getItemCount()
		{
			int count;
			count = this->listView1->get_Items()->Count;
			return count;
		}
	///<summary>
	/// This is used to get the total number of unread items in the inbox
	///</summary>
		int getCheckedItemCount()
		{
			int count;
			count = this->listView1->get_CheckedItems()->Count;
			return count;
		}
		
		//this method updates the statusbar with the info about number of Items and
		//number of Unread Items
		void updateStatusBar()
		{
			int itemCount, checkedItems;
			char *sCount[50], *sChecked[50], *sItems[50], *sUnread[50];
			char buffer[50];
			itemCount = this->getItemCount();
			checkedItems = this->getCheckedItemCount();
			*sCount = itoa(itemCount,buffer,10);
			*sItems = strcat(*sCount," Items, ");
			this->statusBarPanel1->set_Text(*sItems);
			*sChecked = itoa(checkedItems,buffer,10);
			*sUnread = strcat(*sChecked, " Unread");
			this->statusBarPanel1->set_Text(System::String::Concat(this->statusBarPanel1->get_Text(), *sUnread));
			if(checkedItems>0)
			{
				String* temp = System::String::Concat(S"Inbox (",static_cast<String*>(itoa(checkedItems,buffer,10)),S")");
				mailboxFolders->Nodes->get_Item(0)->set_Text(temp);
			}
			else if(checkedItems==0&&itemCount!=0)
			{
				mailboxFolders->Nodes->get_Item(0)->set_Text(S"Inbox");
			}
		}
		

private: System::Void menuItem5_Click(System::Object *  sender, System::EventArgs *  e)
		 {
			 if(this->pop3enabled)
				loginToPop3Server();
			 this->checkForMail();
		 }

///<summary>
	/// This is used to add a new message to the inbox
	///</summary>
		 void addNewEmail()
		 {
			System::String* __mcTemp__1[] = new System::String*[5];
			__mcTemp__1[0] = S"";
			__mcTemp__1[1] = this->from;
			__mcTemp__1[2] = this->subject;
			__mcTemp__1[3] = this->date;
			__mcTemp__1[4] = this->body;
			System::Windows::Forms::ListViewItem *  listViewItemTemp = new System::Windows::Forms::ListViewItem(__mcTemp__1, 1);
			listViewItemTemp->Checked = true;
			
			this->listView1->Items->Add(listViewItemTemp);
		 }

		 bool parseMessage(String* str)
		 {	
			String* delimStr = S"|";
			Char delimiter[] = delimStr->ToCharArray();
			String* split[] = 0;
		
			for (int x = 1; x <= 5; x++) 
			{
					split = str->Split(delimiter, x);
			}
			this->from = split[0];
			this->date = split[1];
			this->subject = split[2];
			this->body = split[3];
			int items = this->listView1->get_Items()->get_Count();
			for(int i = 0; i < items; i++)
			{
				System::Windows::Forms::ListViewItem::ListViewSubItem * t = this->listView1->get_Items()->get_Item(i)->get_SubItems()->get_Item(1);
				if(System::String::Compare(t->get_Text(),this->from)==0)
				{
					t = this->listView1->get_Items()->get_Item(i)->get_SubItems()->get_Item(3);
					if(System::String::Compare(t->get_Text(),this->date)==0)
						return false;
				}
			}
			return true;
		}

		 void checkForMail()
		 {
			 if(this->pop3enabled)
			 {

				int newItems = getNumberOfNewItems();
				for(int i = 1; i <= newItems;i++)
				{
					String* line = getPop3Message(i);
					if(line->CompareTo(S"Invalid email")!=0)
					{
					bool newMess = parseMessage(line);
					if(newMess)
						addNewEmail();
					}
				}
				closePop3();
				this->updateStatusBar();
			 }
		 }


private: System::Void mailboxFolders_AfterSelect(System::Object *  sender, System::Windows::Forms::TreeViewEventArgs *  e)
		 {
			 int nodeIndex = this->mailboxFolders->get_SelectedNode()->get_Index();
			 if(nodeIndex==0)
			 {
				 this->listView1->Visible = true;
				 this->listView1_SelectedIndexChanged(NULL,NULL);
				 this->trashMailbox->Visible = false;
				 this->trashMailbox->SendToBack();
			 }
			 else if(nodeIndex==1)
			 {
				 this->trashMailbox->Visible = true;
				 this->listView1->Visible = false;
				 this->richTextBox1->Clear();
				 this->listView1->SendToBack();
			 }
		 }

private: System::Void listView1_KeyPressEvent(System::Object *  sender, System::Windows::Forms::KeyEventArgs *  e)
		 {
			 if(e->KeyCode == System::Windows::Forms::Keys::Delete)
				{
					ListViewItem * item = new ListViewItem();
					item = this->listView1->SelectedItems->get_Item(0);;
					int index = item->get_Index();
					this->listView1->Items->RemoveAt(index);
					this->trashMailbox->Items->Add(item);
					
				}
		 }
};


}
