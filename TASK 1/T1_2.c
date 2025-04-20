void T1_2()
{
    // hist obj
    TH1F *hist = new TH1F("Impact_Parameters", "Impact_Parameters", 10, 0, 500);

    //file
    ifstream file("Impact_Params.txt");
    double dl;
    while (file >> dl) {
        hist->Fill(dl);
    }
    file.close();

    //Histogram
    TCanvas *c1 = new TCanvas();
    hist->SetFillColor(kBlue-7);
    hist->SetStats(kTRUE);
    hist->GetXaxis()->SetTitle("Impact Parameters (microns)");
    hist->GetYaxis()->SetTitle("Frequency");
    hist->SetTitle("Impact Parameters");
    hist->Draw();
}

