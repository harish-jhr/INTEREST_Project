void T1_1()
{
    // hist obj
    TH1F *hist = new TH1F("Decay_Lengths", "Decay_Lengths", 9, 0, 5000);

    // file
    ifstream file("Decay_Lengths.txt");
    double dl;
    while (file >> dl) {
        hist->Fill(dl);
    }
    file.close();

    //histogram
    TCanvas *c1 = new TCanvas();
    hist->SetFillColor(kBlue-7);
    hist->SetStats(kTRUE);
    hist->GetXaxis()->SetTitle("Decay Length (microns)");  // X-axis title added
    hist->GetYaxis()->SetTitle("Frequency");
    hist->SetTitle("Decay_Lengths");
    hist->Draw();
}
