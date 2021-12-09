#pragma once
#include "Learning_Rules.h"

namespace SingleLayerNeruronNetwork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			//when program runs disable class id combo box
			this->class_id_combo_box->Enabled = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ Coordinate_plane_PictureBox;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ class_id_combo_box;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Set_class_num_button;
	private: System::Windows::Forms::ComboBox^ total_classNum_combo_box;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		///
		int total_class_number;
		int total_points = 0;
		Sample* points;
		int dimension = 2;
		double* weight_array;
		int weight_array_length;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ x2_label;
	private: System::Windows::Forms::Label^ x1_label;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ total_sample_label;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ learningProcessesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ perceptronLearningBinaryFuncToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deltaLearningContinuousFuncToolStripMenuItem;
	private: System::Windows::Forms::Label^ cycle_count_label;
	private: System::Windows::Forms::Label^ label7;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Coordinate_plane_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->class_id_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Set_class_num_button = (gcnew System::Windows::Forms::Button());
			this->total_classNum_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->x2_label = (gcnew System::Windows::Forms::Label());
			this->x1_label = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->total_sample_label = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->learningProcessesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->perceptronLearningBinaryFuncToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaLearningContinuousFuncToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cycle_count_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Coordinate_plane_PictureBox))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Coordinate_plane_PictureBox
			// 
			this->Coordinate_plane_PictureBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Coordinate_plane_PictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Coordinate_plane_PictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Coordinate_plane_PictureBox->Location = System::Drawing::Point(0, 27);
			this->Coordinate_plane_PictureBox->Name = L"Coordinate_plane_PictureBox";
			this->Coordinate_plane_PictureBox->Size = System::Drawing::Size(800, 600);
			this->Coordinate_plane_PictureBox->TabIndex = 0;
			this->Coordinate_plane_PictureBox->TabStop = false;
			this->Coordinate_plane_PictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Coordinate_plane_PictureBox_Paint);
			this->Coordinate_plane_PictureBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Coordinate_plane_PictureBox_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->class_id_combo_box);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->Set_class_num_button);
			this->groupBox1->Controls->Add(this->total_classNum_combo_box);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(838, 45);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(300, 270);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Settings";
			// 
			// class_id_combo_box
			// 
			this->class_id_combo_box->Enabled = false;
			this->class_id_combo_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->class_id_combo_box->FormattingEnabled = true;
			this->class_id_combo_box->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9"
			});
			this->class_id_combo_box->Location = System::Drawing::Point(9, 148);
			this->class_id_combo_box->Name = L"class_id_combo_box";
			this->class_id_combo_box->Size = System::Drawing::Size(80, 24);
			this->class_id_combo_box->TabIndex = 4;
			this->class_id_combo_box->Text = L"1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 116);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(195, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Select Class id To Add a Sample :";
			// 
			// Set_class_num_button
			// 
			this->Set_class_num_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Set_class_num_button->Location = System::Drawing::Point(95, 66);
			this->Set_class_num_button->Name = L"Set_class_num_button";
			this->Set_class_num_button->Size = System::Drawing::Size(167, 25);
			this->Set_class_num_button->TabIndex = 2;
			this->Set_class_num_button->Text = L"Set";
			this->Set_class_num_button->UseVisualStyleBackColor = true;
			this->Set_class_num_button->Click += gcnew System::EventHandler(this, &MyForm::Set_class_num_button_Click);
			// 
			// total_classNum_combo_box
			// 
			this->total_classNum_combo_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->total_classNum_combo_box->FormattingEnabled = true;
			this->total_classNum_combo_box->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9"
			});
			this->total_classNum_combo_box->Location = System::Drawing::Point(9, 66);
			this->total_classNum_combo_box->Name = L"total_classNum_combo_box";
			this->total_classNum_combo_box->Size = System::Drawing::Size(80, 24);
			this->total_classNum_combo_box->TabIndex = 1;
			this->total_classNum_combo_box->Text = L"*";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(256, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Total Number of Classes You Want To Use :";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->cycle_count_label);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->x2_label);
			this->groupBox2->Controls->Add(this->x1_label);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->total_sample_label);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(838, 354);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(300, 192);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Information";
			// 
			// x2_label
			// 
			this->x2_label->AutoSize = true;
			this->x2_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->x2_label->Location = System::Drawing::Point(176, 101);
			this->x2_label->Name = L"x2_label";
			this->x2_label->Size = System::Drawing::Size(11, 13);
			this->x2_label->TabIndex = 9;
			this->x2_label->Text = L"-";
			// 
			// x1_label
			// 
			this->x1_label->AutoSize = true;
			this->x1_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->x1_label->Location = System::Drawing::Point(42, 104);
			this->x1_label->Name = L"x1_label";
			this->x1_label->Size = System::Drawing::Size(11, 13);
			this->x1_label->TabIndex = 8;
			this->x1_label->Text = L"-";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(6, 101);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(30, 16);
			this->label6->TabIndex = 7;
			this->label6->Text = L"X1 :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(139, 101);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"X2 :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(6, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Coordinates :";
			// 
			// total_sample_label
			// 
			this->total_sample_label->AutoSize = true;
			this->total_sample_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->total_sample_label->Location = System::Drawing::Point(175, 32);
			this->total_sample_label->Name = L"total_sample_label";
			this->total_sample_label->Size = System::Drawing::Size(11, 13);
			this->total_sample_label->TabIndex = 4;
			this->total_sample_label->Text = L"-";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 16);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Total Number Of Samples :";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Control;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->learningProcessesToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1184, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// learningProcessesToolStripMenuItem
			// 
			this->learningProcessesToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->learningProcessesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->perceptronLearningBinaryFuncToolStripMenuItem,
					this->deltaLearningContinuousFuncToolStripMenuItem
			});
			this->learningProcessesToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->learningProcessesToolStripMenuItem->Name = L"learningProcessesToolStripMenuItem";
			this->learningProcessesToolStripMenuItem->Size = System::Drawing::Size(124, 20);
			this->learningProcessesToolStripMenuItem->Text = L"Learning Processes";
			// 
			// perceptronLearningBinaryFuncToolStripMenuItem
			// 
			this->perceptronLearningBinaryFuncToolStripMenuItem->Name = L"perceptronLearningBinaryFuncToolStripMenuItem";
			this->perceptronLearningBinaryFuncToolStripMenuItem->Size = System::Drawing::Size(265, 22);
			this->perceptronLearningBinaryFuncToolStripMenuItem->Text = L"Perceptron Learning (Binary func.)";
			this->perceptronLearningBinaryFuncToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::perceptronLearningBinaryFuncToolStripMenuItem_Click);
			// 
			// deltaLearningContinuousFuncToolStripMenuItem
			// 
			this->deltaLearningContinuousFuncToolStripMenuItem->Name = L"deltaLearningContinuousFuncToolStripMenuItem";
			this->deltaLearningContinuousFuncToolStripMenuItem->Size = System::Drawing::Size(265, 22);
			this->deltaLearningContinuousFuncToolStripMenuItem->Text = L"Delta Learning (Continuous func.)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(6, 140);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(220, 16);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Number of Cycles in Training Rules : ";
			// 
			// cycle_count_label
			// 
			this->cycle_count_label->AutoSize = true;
			this->cycle_count_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cycle_count_label->Location = System::Drawing::Point(232, 143);
			this->cycle_count_label->Name = L"cycle_count_label";
			this->cycle_count_label->Size = System::Drawing::Size(11, 13);
			this->cycle_count_label->TabIndex = 12;
			this->cycle_count_label->Text = L"-";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 641);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Coordinate_plane_PictureBox);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Single Layer Network";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Coordinate_plane_PictureBox))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//###############################################################################################################################################################################################################

	// Draw the horizontal and vertical lines on coordinate plane 
	private: System::Void Coordinate_plane_PictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ pen_color = gcnew Pen(Color::Black, 2.0f);
		int center_width = (int)(Coordinate_plane_PictureBox->Width / 2);
		int center_height = (int)(Coordinate_plane_PictureBox->Height / 2);
		// draw vertical line
		e->Graphics->DrawLine(pen_color, center_width, 0, center_width, Coordinate_plane_PictureBox->Height);
		// draw horizontal line
		e->Graphics->DrawLine(pen_color, 0, center_height, Coordinate_plane_PictureBox->Width, center_height);
	}

//###############################################################################################################################################################################################################

	// take total number of classes that user choose and put it in a variable called 'total_class_number'
	private: System::Void Set_class_num_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// users only can choose number of classes between 2-9 inside combo box and if they enter anything else we give them a message to select number form combobox
		if (!check_combobox_selection((char)(Convert::ToChar(total_classNum_combo_box->Text))))
			MessageBox::Show("Setting the total number of classes by choosing an option from the combo box.");
		else {
			class_id_combo_box->Enabled = true;
			total_class_number = Convert::ToInt16(total_classNum_combo_box->Text);

			// if user choose 2 classes then we just need to draw one line to separate them that is why we set it to 1
			if (total_class_number == 2)
				total_class_number = 1;

			// the rows of our weight matrix is equal to total class number and the colums are equal to inputs + 1 ( because we are going to choose our input from coordinate palne
			// the input number is always equal to 2. the +1  is because we also add bias constant to our input matrix)
			weight_array_length = total_class_number * (dimension + 1);
			weight_array = new double[weight_array_length];
		}
	}

//##############################################################################################################################################################################################################

	private: System::Void Coordinate_plane_PictureBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int x1_coordinate = Convert::ToInt32(e->X);
		int x2_coordinate = Convert::ToInt32(e->Y);

		double transferred_x1 = (double)(x1_coordinate - (Coordinate_plane_PictureBox->Width / 2));
		double transferred_x2 = (double)((Coordinate_plane_PictureBox->Height / 2) - x2_coordinate);

		int class_id;
		// check if user already set total class number
		if (class_id_combo_box->Enabled == true) {
			class_id = class_id_combo_box->SelectedIndex;

			//chech if the point is the first point ever added
			if (total_points == 0) {
				total_points++;
				points = new Sample[1];
				points->x_coordinates = new double[dimension];
				points[0].x_coordinates[0] = transferred_x1;
				points[0].x_coordinates[1] = transferred_x2;
				points[0].class_id = class_id;

			}
			else {
				total_points++;
				points = add_sample_to_points(points, total_points, transferred_x1, transferred_x2, class_id, dimension);
			}

			// set different color to every class according to its class id.
			Pen^ pen;
			switch (class_id) {
			case 0: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Green, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Pink, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 6: pen = gcnew Pen(Color::Aqua, 3.0f); break;
			case 7: pen = gcnew Pen(Color::Brown, 3.0f); break;
			case 8: pen = gcnew Pen(Color::Purple, 3.0f); break;
			default: pen = gcnew Pen(Color::Black, 3.0f);
			}

			Coordinate_plane_PictureBox->CreateGraphics()->DrawLine(pen, x1_coordinate - 5, x2_coordinate, x1_coordinate + 5, x2_coordinate);
			Coordinate_plane_PictureBox->CreateGraphics()->DrawLine(pen, x1_coordinate, x2_coordinate - 5, x1_coordinate, x2_coordinate + 5);
			total_sample_label->Text = Convert::ToString(total_points);
			x1_label->Text = Convert::ToString(transferred_x1);
			x2_label->Text = Convert::ToString(transferred_x2);


		}
		else {
			MessageBox::Show("You need to first specify total class number then you can add sample for desired class id.");
		}
	}

//##############################################################################################################################################################################################################

	// when user click on precetron learning from toolbar
	private: System::Void perceptronLearningBinaryFuncToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		set_random_value_to_array(weight_array, weight_array_length);
		int cycle = 100000;
		bool stop_training = false;

		int* training_return_values = new int[total_points];
		int cycle_count;
		for (cycle_count = 0; cycle_count < cycle; cycle_count++) {
			stop_training = true;
			for (int i = 0; i < total_points; i++) {
				training_return_values[i] = perceptron_learning(points[i], weight_array, dimension, total_class_number);
			}

			for (int j = 0; j < total_points; j++) {
				if (training_return_values[j] == 0) {
					stop_training = false;
				}
			}
			if (stop_training) {
				break;
			}
		}

		cycle_count_label->Text = cycle_count.ToString();
		for (int i = 0; i < total_class_number; i++) {

			Pen^ pen;
			switch (i) {
			case 0: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Green, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Pink, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 6: pen = gcnew Pen(Color::Aqua, 3.0f); break;
			case 7: pen = gcnew Pen(Color::Brown, 3.0f); break;
			case 8: pen = gcnew Pen(Color::Purple, 3.0f); break;
			default: pen = gcnew Pen(Color::Black, 3.0f);
			}

			int min_x, min_y, max_x, max_y;
			min_x = (this->Coordinate_plane_PictureBox->Width) / -2;
			min_y = find_y_point(min_x, &weight_array[i * (dimension + 1)]);
			max_x = (this->Coordinate_plane_PictureBox->Width) / 2;
			max_y = find_y_point(max_x, &weight_array[i * (dimension + 1)]);
			Coordinate_plane_PictureBox->CreateGraphics()->DrawLine(pen, max_x + min_x, (Coordinate_plane_PictureBox->Height / 2) - min_y, max_x + max_x, (Coordinate_plane_PictureBox->Height / 2) - max_y);

		}
	}
};
}
