#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

extern "C++"
{
	void setSmtpServerAddress(String*,int);
	void setPop3ServerAddress(String*,int);
	void setUserInfo(String*,String*);
	String* loginToPop3Server();
}

namespace SMTPemailclient
{
	/// <summary> 
	/// Summary for loginForm
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public __gc class loginForm : public System::Windows::Forms::Form
	{
	public: 
		loginForm(void)
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
	private: System::Windows::Forms::Label *  label1;
	private: System::Windows::Forms::Label *  label2;
	private: System::Windows::Forms::Label *  label3;
	private: System::Windows::Forms::Label *  label4;
	
	private: System::Windows::Forms::PictureBox *  pictureBox1;
	private: System::Windows::Forms::Button *  button1;
	private: System::Windows::Forms::Button *  button2;
	private: System::Windows::Forms::TextBox *  serverTextBox;
	private: System::Windows::Forms::TextBox *  usernameTextBox;
	private: System::Windows::Forms::TextBox *  passwordTextBox;
	private: System::Windows::Forms::ErrorProvider *  loginError;
	private: System::Windows::Forms::CheckBox *  checkBox1;
	private: bool pop3enabled;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container* components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(SMTPemailclient::loginForm));
			this->label1 = new System::Windows::Forms::Label();
			this->label2 = new System::Windows::Forms::Label();
			this->label3 = new System::Windows::Forms::Label();
			this->label4 = new System::Windows::Forms::Label();
			this->serverTextBox = new System::Windows::Forms::TextBox();
			this->usernameTextBox = new System::Windows::Forms::TextBox();
			this->passwordTextBox = new System::Windows::Forms::TextBox();
			this->pictureBox1 = new System::Windows::Forms::PictureBox();
			this->button1 = new System::Windows::Forms::Button();
			this->button2 = new System::Windows::Forms::Button();
			this->loginError = new System::Windows::Forms::ErrorProvider();
			this->checkBox1 = new System::Windows::Forms::CheckBox();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->label1->Location = System::Drawing::Point(88, 32);
			this->label1->Name = S"label1";
			this->label1->Size = System::Drawing::Size(296, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = S"Please type your user name and password.";
			// 
			// label2
			// 
			this->label2->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->label2->Location = System::Drawing::Point(96, 72);
			this->label2->Name = S"label2";
			this->label2->Size = System::Drawing::Size(88, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = S"Server:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->label3->Location = System::Drawing::Point(96, 112);
			this->label3->Name = S"label3";
			this->label3->Size = System::Drawing::Size(88, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = S"User name:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->label4->Location = System::Drawing::Point(96, 152);
			this->label4->Name = S"label4";
			this->label4->Size = System::Drawing::Size(88, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = S"Password:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// serverTextBox
			// 
			this->serverTextBox->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->serverTextBox->Location = System::Drawing::Point(192, 73);
			this->serverTextBox->Name = S"serverTextBox";
			this->serverTextBox->Size = System::Drawing::Size(272, 22);
			this->serverTextBox->TabIndex = 1;
			this->serverTextBox->Text = S"";
			// 
			// usernameTextBox
			// 
			this->usernameTextBox->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->usernameTextBox->Location = System::Drawing::Point(192, 113);
			this->usernameTextBox->Name = S"usernameTextBox";
			this->usernameTextBox->Size = System::Drawing::Size(272, 22);
			this->usernameTextBox->TabIndex = 2;
			this->usernameTextBox->Text = S"";
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->passwordTextBox->Location = System::Drawing::Point(192, 153);
			this->passwordTextBox->Name = S"passwordTextBox";
			this->passwordTextBox->PasswordChar = '*';
			this->passwordTextBox->Size = System::Drawing::Size(272, 22);
			this->passwordTextBox->TabIndex = 3;
			this->passwordTextBox->Text = S"";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (__try_cast<System::Drawing::Image *  >(resources->GetObject(S"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(24, 56);
			this->pictureBox1->Name = S"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(64, 72);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->button1->Location = System::Drawing::Point(288, 224);
			this->button1->Name = S"button1";
			this->button1->Size = System::Drawing::Size(72, 32);
			this->button1->TabIndex = 4;
			this->button1->Text = S"OK";
			this->button1->Click += new System::EventHandler(this, button1_Click);
			// 
			// button2
			// 
			this->button2->Font = new System::Drawing::Font(S"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
			this->button2->Location = System::Drawing::Point(392, 224);
			this->button2->Name = S"button2";
			this->button2->Size = System::Drawing::Size(72, 32);
			this->button2->TabIndex = 5;
			this->button2->Text = S"Cancel";
			this->button2->Click += new System::EventHandler(this, button2_Click);
			// 
			// loginError
			// 
			this->loginError->ContainerControl = this;
			// 
			// checkBox1
			// 
			this->checkBox1->Location = System::Drawing::Point(48, 200);
			this->checkBox1->Name = S"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(152, 24);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = S"login without pop3";
			// 
			// loginForm
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(482, 272);
			this->ControlBox = false;
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->usernameTextBox);
			this->Controls->Add(this->serverTextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = S"loginForm";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = S"Please Sign in";
			this->TopMost = true;
			this->ResumeLayout(false);

		}		



private: System::Void button2_Click(System::Object *  sender, System::EventArgs *  e)
		 {
			 exit(0);
		 }

private: System::Void button1_Click(System::Object *  sender, System::EventArgs *  e)
		 {

			String* server = S""; String* smtpServer = S""; String* pop3Server = S"";
			String* username = S""; String* password = S""; String* serverMessage = S"";
			Char delimStr = '.';
			int index;
			if(this->checkBox1->Checked)
			{
				pop3enabled = false;
				if(this->serverTextBox->get_Text()->Equals(S""))
				{
					loginError->SetIconAlignment(this->serverTextBox,ErrorIconAlignment::MiddleLeft);
					loginError->SetError(this->usernameTextBox,S"You must at least specify a server address");
				}
				else
				{
					server = this->serverTextBox->get_Text();
					index = server->IndexOf(delimStr);
					server = server->Remove(0,index);
					smtpServer = System::String::Concat("mail",server);
					setSmtpServerAddress(smtpServer,25);
					
					this->Hide();
				}
			}
			else
			{
				server = this->serverTextBox->get_Text();
				username = this->usernameTextBox->get_Text();
				password = this->passwordTextBox->get_Text();
				
				index = server->IndexOf(delimStr);
				server = server->Remove(0,index);
				smtpServer = System::String::Concat("mail",server);
				pop3Server = System::String::Concat("pop3",server);
				setSmtpServerAddress(smtpServer,25);
				setPop3ServerAddress(pop3Server,110);
				setUserInfo(username,password);
				bool connected = processServerMessage(loginToPop3Server());
				if(connected)
					this->Hide();
				else
				{
					loginError->SetIconAlignment(this->usernameTextBox,ErrorIconAlignment::MiddleLeft);
					loginError->SetError(this->usernameTextBox,S"ERROR: \n\nIncorrect username and or password, please try again");
					this->usernameTextBox->Text = "";
					this->passwordTextBox->Text = "";
				}
			}
		 }

		 bool processServerMessage(String* message)
		 {
			 if(message->StartsWith(S"+OK"))
				return true;
			 else
				return false;
		 }

		 public: bool getpop3enabled()
		 {
			return pop3enabled;
		 }
};

}